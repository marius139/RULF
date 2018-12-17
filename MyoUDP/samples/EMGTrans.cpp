// This sample illustrates how to use EMG data. EMG streaming is only supported for one Myo at a time.
// Enables transmission of EMG via UDP on Localhost port 54000

#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include <bitset>
#include <WS2tcpip.h>
#include <myo/myo.hpp>

#pragma comment (lib, "ws2_32.lib")

WSADATA data;
WORD version = MAKEWORD(2, 2);
int wsOk = WSAStartup(version, &data);
sockaddr_in server;
char emgdata[8];


// Socket creation, note that the socket type is datagram - This is used for UDP
SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);

class DataCollector : public myo::DeviceListener {
public:
	DataCollector() : emgSamples() {}

	// onUnpair() is called whenever the Myo is disconnected from Myo Connect by the user.
	void onUnpair(myo::Myo* myo, uint64_t timestamp)
	{
		// We've lost a Myo.
		// Let's clean up some leftover state.
		emgSamples.fill(0);
	}

	// onEmgData() is called whenever a paired Myo has provided new EMG data, and EMG streaming is enabled.
	// This is the function that transmit data via UDP
	void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg)
	{
		for (int i = 0; i < 8; i++) {
			emgSamples[i] = emg[i];
		}
		for (int i = 0; i < 8; i++) {
			emgdata[i] = emg[i];
		}
		//Using Winsock to send data
		int sendOk = sendto(out, emgdata, sizeof(emgdata), 0, (sockaddr*)&server, sizeof(server));

	}

	// There are other virtual functions in DeviceListener that we could override here, like onAccelerometerData().
	// For this example, the functions overridden above are sufficient.

	// We define this function to print the current values that were updated by the on...() functions above.
	void print()
	{
		// Clear the current line
		std::cout << '\r';

		// Print out the EMG data.
		for (size_t i = 0; i < emgSamples.size(); i++) {
			std::ostringstream oss;
			oss << static_cast<int>(emgSamples[i]);
			std::string emgString = oss.str();

			std::cout << '[' << emgString << std::string(4 - emgString.size(), ' ') << ']';
		}
		//emgSamples.c_str()


		std::cout << std::flush;
	}

	// The values of this array is set by onEmgData() above.
	std::array<int8_t, 8> emgSamples;
};

int main(int argc, char** argv)
{
	//Declaration of server variables for the UDP connection
	server.sin_family = AF_INET; // AF_INET = IPv4 addresses
	server.sin_port = htons(54000); // Little to big endian conversion
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr); // Convert from string to byte array

	try {

		// First, we create a Hub with our application identifier. The Hub provides access to one or more Myos.
		myo::Hub hub("com.EMGTrans.emg-sample"); 

		std::cout << "Attempting to find a Myo..." << std::endl;

		// Next, we attempt to find a Myo to use. If a Myo is already paired in Myo Connect, this will return that Myo
		// immediately.
		// waitForMyo() takes a timeout value in milliseconds. In this case we will try to find a Myo for 10 seconds, and
		// if that fails, the function will return a null pointer.
		myo::Myo* myo = hub.waitForMyo(10000);

		// If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
		if (!myo) {
			throw std::runtime_error("Unable to find a Myo!");
		}

		// We've found a Myo.
		std::cout << "Connected to a Myo armband!" << std::endl << std::endl;

		// Next we enable EMG streaming on the found Myo.
		myo->setStreamEmg(myo::Myo::streamEmgEnabled);

		// Next we construct an instance of our DeviceListener, so that we can register it with the Hub.
		DataCollector collector;

		// Hub::addListener() takes the address of any object whose class inherits from DeviceListener, and will cause
		// Hub::run() to send events to all registered device listeners.
		hub.addListener(&collector);

		// Finally we enter our main loop.
		while (1) {
			// In each iteration of our main loop, we run the Myo event loop for a set number of milliseconds.
			// In this case, we wish to update our display 50 times a second, so we run for 1000/20 milliseconds.
			hub.run(1000 / 20);
			// After processing events, we call the print() member function we defined above to print out the values we've
			// obtained from any events that have occurred.
			collector.print();
		}

		// If a standard exception occurred, we print out its message and exit.
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Press enter to continue.";
		std::cin.ignore();
		return 1;
	}
}