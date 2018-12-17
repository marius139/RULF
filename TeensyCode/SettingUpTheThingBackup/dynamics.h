

float dynamics (int id, float a1, float a2, float a3, float vel1, float vel2, float vel3, float th1, float th2, float th3) {

    float m11, m21, m31, m12, m22, m32, m13, m23, m33, v11, v21, v31, g11, g21, g31;
    float g=-9.81;



//    Conversion to RAD/sec
    float v1= (vel1*0.229)*((PI*2.0)/60.0);
    float v2= (vel2*0.229)*((PI*2.0)/60.0);
	float v3= (vel3*0.229)*((PI*2.0)/60.0);

  
//Calculation of dynamics
    m11= (85865525619.0*cos(th3))/10000000000000.0 - (209957596367.0*cos(2.0*th2))/20000000000000.0 - (8668961990246401.0*sin(2.0*th2))/343597383680000000000000.0 - (50567338383.0*cos(2.0*th2 + 2.0*th3))/20000000000000.0 - (6443309937459201.0*sin(2.0*th2 + 2.0*th3))/42949672960000000000000.0 - (85865525619.0*cos(2.0*th2 + th3))/10000000000000.0 + 5845695419.0/400000000000.0;
    m21= (8668961990246401.0*cos(2.0*th2)*sin(th1))/343597383680000000000000.0 - (230913.0*cos(th1)*sin(th2))/100000000000.0 - (169237.0*cos(th1)*cos(th2))/12500000000.0 - (209957596367.0*sin(2.0*th2)*sin(th1))/20000000000000.0 + (714951.0*cos(th1)*sin(th2)*sin(th3))/100000000000.0 - (85865525619.0*cos(2.0*th2)*sin(th1)*sin(th3))/10000000000000.0 - (85865525619.0*sin(2.0*th2)*cos(th3)*sin(th1))/10000000000000.0 + (6443309937459201.0*cos(2.0*th2)*cos(2.0*th3)*sin(th1))/42949672960000000000000.0 - (50567338383.0*cos(2.0*th2)*sin(2.0*th3)*sin(th1))/20000000000000.0 - (50567338383.0*cos(2.0*th3)*sin(2.0*th2)*sin(th1))/20000000000000.0 - (6443309937459201.0*sin(2.0*th2)*sin(2.0*th3)*sin(th1))/42949672960000000000000.0 - (714951.0*cos(th1)*cos(th2)*cos(th3))/100000000000.0 + (155797.0*cos(th1)*cos(th2)*sin(th3))/50000000000.0 + (155797.0*cos(th1)*cos(th3)*sin(th2))/50000000000.0;
    m31= (85865525619.0*sin(th1)*sin(th3))/20000000000000.0 + (714951.0*cos(th1)*sin(th2)*sin(th3))/100000000000.0 - (85865525619.0*cos(2.0*th2)*sin(th1)*sin(th3))/20000000000000.0 - (85865525619.0*sin(2.0*th2)*cos(th3)*sin(th1))/20000000000000.0 + (6443309937459201.0*cos(2.0*th2)*cos(2.0*th3)*sin(th1))/42949672960000000000000.0 - (50567338383.0*cos(2.0*th2)*sin(2.0*th3)*sin(th1))/20000000000000.0 - (50567338383.0*cos(2.0*th3)*sin(2.0*th2)*sin(th1))/20000000000000.0 - (6443309937459201.0*sin(2.0*th2)*sin(2.0*th3)*sin(th1))/42949672960000000000000.0 - (714951.0*cos(th1)*cos(th2)*cos(th3))/100000000000.0 + (155797.0*cos(th1)*cos(th2)*sin(th3))/50000000000.0 + (155797.0*cos(th1)*cos(th3)*sin(th2))/50000000000.0;
    m12= m21;
    m22= (4766588171.0*cos(2.0*th1))/800000000000.0 + (209957596367.0*cos(2.0*th2))/40000000000000.0 + (8668961990246401.0*sin(2.0*th2))/687194767360000000000000.0 + (257596576857.0*cos(th3))/20000000000000.0 + (85865525619.0*cos(2.0*th1)*cos(th3))/20000000000000.0 + (85865525619.0*cos(2.0*th2)*cos(th3))/20000000000000.0 + (230913.0*sin(2.0*th1)*cos(th2))/100000000000.0 - (169237.0*sin(2.0*th1)*sin(th2))/12500000000.0 - (85865525619.0*sin(2.0*th2)*sin(th3))/20000000000000.0 - (209957596367.0*cos(2.0*th1)*cos(2.0*th2))/40000000000000.0 + (50567338383.0*cos(2.0*th2)*cos(2.0*th3))/40000000000000.0 - (8668961990246401.0*cos(2.0*th1)*sin(2.0*th2))/687194767360000000000000.0 + (6443309937459201.0*cos(2.0*th2)*sin(2.0*th3))/85899345920000000000000.0 + (6443309937459201.0*cos(2.0*th3)*sin(2.0*th2))/85899345920000000000000.0 - (50567338383.0*sin(2.0*th2)*sin(2.0*th3))/40000000000000.0 - (50567338383.0*cos(2.0*th1)*cos(2.0*th2)*cos(2.0*th3))/40000000000000.0 - (6443309937459201.0*cos(2.0*th1)*cos(2.0*th2)*sin(2.0*th3))/85899345920000000000000.0 - (6443309937459201.0*cos(2.0*th1)*cos(2.0*th3)*sin(2.0*th2))/85899345920000000000000.0 + (50567338383.0*cos(2.0*th1)*sin(2.0*th2)*sin(2.0*th3))/40000000000000.0 - (155797.0*sin(2.0*th1)*cos(th2)*cos(th3))/50000000000.0 - (714951.0*sin(2.0*th1)*cos(th2)*sin(th3))/100000000000.0 - (714951.0*sin(2.0*th1)*cos(th3)*sin(th2))/100000000000.0 + (155797.0*sin(2.0*th1)*sin(th2)*sin(th3))/50000000000.0 - (85865525619.0*cos(2.0*th1)*cos(2.0*th2)*cos(th3))/20000000000000.0 + (85865525619.0*cos(2.0*th1)*sin(2.0*th2)*sin(th3))/20000000000000.0 + 16322517193.0/800000000000.0;
    m32= (43360083983.0*cos(2.0*th1))/40000000000000.0 + (257596576857.0*cos(th3))/40000000000000.0 + (85865525619.0*cos(2.0*th1)*cos(th3))/40000000000000.0 + (85865525619.0*cos(2.0*th2)*cos(th3))/40000000000000.0 - (85865525619.0*sin(2.0*th2)*sin(th3))/40000000000000.0 + (50567338383.0*cos(2.0*th2)*cos(2.0*th3))/40000000000000.0 + (6443309937459201.0*cos(2.0*th2)*sin(2.0*th3))/85899345920000000000000.0 + (6443309937459201.0*cos(2.0*th3)*sin(2.0*th2))/85899345920000000000000.0 - (50567338383.0*sin(2.0*th2)*sin(2.0*th3))/40000000000000.0 - (50567338383.0*cos(2.0*th1)*cos(2.0*th2)*cos(2.0*th3))/40000000000000.0 - (6443309937459201.0*cos(2.0*th1)*cos(2.0*th2)*sin(2.0*th3))/85899345920000000000000.0 - (6443309937459201.0*cos(2.0*th1)*cos(2.0*th3)*sin(2.0*th2))/85899345920000000000000.0 + (50567338383.0*cos(2.0*th1)*sin(2.0*th2)*sin(2.0*th3))/40000000000000.0 - (155797.0*sin(2.0*th1)*cos(th2)*cos(th3))/50000000000.0 - (714951.0*sin(2.0*th1)*cos(th2)*sin(th3))/100000000000.0 - (714951.0*sin(2.0*th1)*cos(th3)*sin(th2))/100000000000.0 + (155797.0*sin(2.0*th1)*sin(th2)*sin(th3))/50000000000.0 - (85865525619.0*cos(2.0*th1)*cos(2.0*th2)*cos(th3))/40000000000000.0 + (85865525619.0*cos(2.0*th1)*sin(2.0*th2)*sin(th3))/40000000000000.0 + 168047536749.0/40000000000000.0;
    m13= m31;
    m23= m32;
    m33= (43360083983.0*cos(2.0*th1))/40000000000000.0 + (50567338383.0*cos(2.0*th2)*cos(2.0*th3))/40000000000000.0 + (6443309937459201.0*cos(2.0*th2)*sin(2.0*th3))/85899345920000000000000.0 + (6443309937459201.0*cos(2.0*th3)*sin(2.0*th2))/85899345920000000000000.0 - (50567338383.0*sin(2.0*th2)*sin(2.0*th3))/40000000000000.0 - (50567338383.0*cos(2.0*th1)*cos(2.0*th2)*cos(2.0*th3))/40000000000000.0 - (6443309937459201.0*cos(2.0*th1)*cos(2.0*th2)*sin(2.0*th3))/85899345920000000000000.0 - (6443309937459201.0*cos(2.0*th1)*cos(2.0*th3)*sin(2.0*th2))/85899345920000000000000.0 + (50567338383.0*cos(2.0*th1)*sin(2.0*th2)*sin(2.0*th3))/40000000000000.0 - (155797.0*sin(2.0*th1)*cos(th2)*cos(th3))/50000000000.0 - (714951.0*sin(2.0*th1)*cos(th2)*sin(th3))/100000000000.0 - (714951.0*sin(2.0*th1)*cos(th3)*sin(th2))/100000000000.0 + (155797.0*sin(2.0*th1)*sin(th2)*sin(th3))/50000000000.0 + 168047536749.0/40000000000000.0;
    ////
    v11=(3998503966395597.0*v2*v2*sin(2.0*th1))/671088640000000000.0 + (43360083983.0*v3*v3*sin(2.0*th1))/40000000000000.0 - (681534882286799.0*v2*v2*cos(2.0*th1)*cos(th2))/295147905179352825856.0 + (7991991364614101.0*v2*v2*cos(2.0*th1)*sin(th2))/590295810358705651712.0 + (85865525619.0*v2*v2*sin(2.0*th1)*cos(th3))/20000000000000.0 + (43360083983.0*v2*v3*sin(2.0*th1))/20000000000000.0- (209957596367.0*v2*v2*cos(2.0*th2)*sin(2.0*th1))/40000000000000.0 - (3812649803609637.0*v2*v2*sin(2.0*th1)*sin(2.0*th2))/302231454903657293676544.0 + (50567338383.0*v2*v2*sin(2.0*th1)*sin(2.0*th2)*sin(2.0*th3))/40000000000000.0 + (50567338383.0*v3*v3*sin(2.0*th1)*sin(2.0*th2)*sin(2.0*th3))/40000000000000.0- (7991991364614101.0*v1*v2*cos(th2)*sin(th1))/590295810358705651712.0 - (85865525619.0*v1*v3*cos(th1)*sin(th3))/20000000000000.0 - (681534882286799.0*v1*v2*sin(th1)*sin(th2))/295147905179352825856.0 + (7357305309316421.0*v2*v2*cos(2.0*th1)*cos(th2)*cos(th3))/2361183241434822606848.0 + (7357305309316421.0*v3*v3*cos(2.0*th1)*cos(th2)*cos(th3))/2361183241434822606848.0 + (2110162899558835.0*v2*v2*cos(2.0*th1)*cos(th2)*sin(th3))/295147905179352825856.0+ (2110162899558835.0*v2*v2*cos(2.0*th1)*cos(th3)*sin(th2))/295147905179352825856.0+ (2110162899558835.0*v3*v3*cos(2.0*th1)*cos(th2)*sin(th3))/295147905179352825856.0+ (2110162899558835.0*v3*v3*cos(2.0*th1)*cos(th3)*sin(th2))/295147905179352825856.0- (7357305309316421.0*v2*v2*cos(2.0*th1)*sin(th2)*sin(th3))/2361183241434822606848.0- (7357305309316421.0*v3*v3*cos(2.0*th1)*sin(th2)*sin(th3))/2361183241434822606848.0- (3812649803609637.0*v1*v2*cos(2.0*th2)*cos(th1))/151115727451828646838272.0+ (209957596367.0*v1*v2*sin(2.0*th2)*cos(th1))/20000000000000.0 + (85865525619.0*v2*v3*sin(2.0*th1)*cos(th3))/20000000000000.0 - (85865525619.0*v2*v2*cos(2.0*th2)*sin(2.0*th1)*cos(th3))/20000000000000.0 + (85865525619.0*v2*v2*sin(2.0*th1)*sin(2.0*th2)*sin(th3))/20000000000000.0- (50567338383.0*v2*v2*cos(2.0*th2)*cos(2.0*th3)*sin(2.0*th1))/40000000000000.0 - (50567338383.0*v3*v3*cos(2.0*th2)*cos(2.0*th3)*sin(2.0*th1))/40000000000000.0 - (2833797679040417.0*v2*v2*cos(2.0*th2)*sin(2.0*th1)*sin(2.0*th3))/37778931862957161709568.0- (2833797679040417.0*v2*v2*cos(2.0*th3)*sin(2.0*th1)*sin(2.0*th2))/37778931862957161709568.0- (2833797679040417.0*v3*v3*cos(2.0*th2)*sin(2.0*th1)*sin(2.0*th3))/37778931862957161709568.0- (2833797679040417.0*v3*v3*cos(2.0*th3)*sin(2.0*th1)*sin(2.0*th2))/37778931862957161709568.0- (50567338383.0*v2*v3*cos(2.0*th2)*cos(2.0*th3)*sin(2.0*th1))/20000000000000.0+ (2110162899558835.0*v1*v2*sin(th1)*sin(th2)*sin(th3))/295147905179352825856.0+ (2110162899558835.0*v1*v3*sin(th1)*sin(th2)*sin(th3))/295147905179352825856.0- (2833797679040417.0*v2*v3*cos(2.0*th2)*sin(2.0*th1)*sin(2.0*th3))/18889465931478580854784.0 - (2833797679040417.0*v2*v3*cos(2.0*th3)*sin(2.0*th1)*sin(2.0*th2))/18889465931478580854784.0+ (50567338383.0*v2*v3*sin(2.0*th1)*sin(2.0*th2)*sin(2.0*th3))/20000000000000.0 + (7357305309316421.0*v2*v3*cos(2.0*th1)*cos(th2)*cos(th3))/1180591620717411303424.0 + (85865525619.0*v1*v2*cos(2.0*th2)*cos(th1)*sin(th3))/10000000000000.0+ (85865525619.0*v1*v2*sin(2.0*th2)*cos(th1)*cos(th3))/10000000000000.0+(85865525619.0*v1*v3*cos(2.0*th2)*cos(th1)*sin(th3))/20000000000000.0+ (85865525619.0*v1*v3*sin(2.0*th2)*cos(th1)*cos(th3))/20000000000000.0+ (2110162899558835.0*v2*v3*cos(2.0*th1)*cos(th2)*sin(th3))/147573952589676412928.0 + (2110162899558835.0*v2*v3*cos(2.0*th1)*cos(th3)*sin(th2))/147573952589676412928.0 - (7357305309316421.0*v2*v3*cos(2.0*th1)*sin(th2)*sin(th3))/1180591620717411303424.0- (2833797679040417.0*v1*v2*cos(2.0*th2)*cos(2.0*th3)*cos(th1))/18889465931478580854784.0- (2833797679040417.0*v1*v3*cos(2.0*th2)*cos(2.0*th3)*cos(th1))/18889465931478580854784.0+ (50567338383.0*v1*v2*cos(2.0*th2)*sin(2.0*th3)*cos(th1))/20000000000000.0+ (50567338383.0*v1*v2*cos(2.0*th3)*sin(2.0*th2)*cos(th1))/20000000000000.0+ (50567338383.0*v1*v3*cos(2.0*th2)*sin(2.0*th3)*cos(th1))/20000000000000.0 + (50567338383.0*v1*v3*cos(2.0*th3)*sin(2.0*th2)*cos(th1))/20000000000000.0 - (85865525619.0*v2*v3*cos(2.0*th2)*sin(2.0*th1)*cos(th3))/20000000000000.0 + (2833797679040417.0*v1*v2*sin(2.0*th2)*sin(2.0*th3)*cos(th1))/18889465931478580854784.0+ (2833797679040417.0*v1*v3*sin(2.0*th2)*sin(2.0*th3)*cos(th1))/18889465931478580854784.0+ (85865525619.0*v2*v3*sin(2.0*th1)*sin(2.0*th2)*sin(th3))/20000000000000.0 - (2110162899558835.0*v1*v2*cos(th2)*cos(th3)*sin(th1))/295147905179352825856.0 - (2110162899558835.0*v1*v3*cos(th2)*cos(th3)*sin(th1))/295147905179352825856.0 + (7357305309316421.0*v1*v2*cos(th2)*sin(th1)*sin(th3))/2361183241434822606848.0+ (7357305309316421.0*v1*v2*cos(th3)*sin(th1)*sin(th2))/2361183241434822606848.0+ (7357305309316421.0*v1*v3*cos(th2)*sin(th1)*sin(th3))/2361183241434822606848.0+ (7357305309316421.0*v1*v3*cos(th3)*sin(th1)*sin(th2))/2361183241434822606848.0;
    v21=(3812649803609637.0*v1*v1*cos(2.0*th2))/151115727451828646838272.0 - (3812649803609637.0*v2*v2*cos(2.0*th2))/302231454903657293676544.0 - (209957596367.0*v1*v1*sin(2.0*th2))/20000000000000.0+ (209957596367.0*v2*v2*sin(2.0*th2))/40000000000000.0 + (7991991364614101.0*v2*v2*sin(2.0*th1)*cos(th2))/1180591620717411303424.0- (85865525619.0*v1*v1*cos(2.0*th2)*sin(th3))/10000000000000.0 - (85865525619.0*v1*v1*sin(2.0*th2)*cos(th3))/10000000000000.0 + (85865525619.0*v2*v2*cos(2.0*th2)*sin(th3))/20000000000000.0 + (85865525619.0*v2*v2*sin(2.0*th2)*cos(th3))/20000000000000.0 + (681534882286799.0*v2*v2*sin(2.0*th1)*sin(th2))/590295810358705651712.0 + (3812649803609637.0*v2*v2*cos(2.0*th1)*cos(2.0*th2))/302231454903657293676544.0+ (2833797679040417.0*v1*v1*cos(2.0*th2)*cos(2.0*th3))/18889465931478580854784.0 - (2833797679040417.0*v2*v2*cos(2.0*th2)*cos(2.0*th3))/37778931862957161709568.0 - (2833797679040417.0*v3*v3*cos(2.0*th2)*cos(2.0*th3))/37778931862957161709568.0 - (209957596367.0*v2*v2*cos(2.0*th1)*sin(2.0*th2))/40000000000000.0 - (50567338383.0*v1*v1*cos(2.0*th2)*sin(2.0*th3))/20000000000000.0- (50567338383.0*v1*v1*cos(2.0*th3)*sin(2.0*th2))/20000000000000.0 + (50567338383.0*v2*v2*cos(2.0*th2)*sin(2.0*th3))/40000000000000.0 + (50567338383.0*v2*v2*cos(2.0*th3)*sin(2.0*th2))/40000000000000.0 + (50567338383.0*v3*v3*cos(2.0*th2)*sin(2.0*th3))/40000000000000.0 + (50567338383.0*v3*v3*cos(2.0*th3)*sin(2.0*th2))/40000000000000.0 - (2833797679040417.0*v1*v1*sin(2.0*th2)*sin(2.0*th3))/18889465931478580854784.0+ (2833797679040417.0*v2*v2*sin(2.0*th2)*sin(2.0*th3))/37778931862957161709568.0+ (2833797679040417.0*v3*v3*sin(2.0*th2)*sin(2.0*th3))/37778931862957161709568.0-(7991991364614101.0*v1*v2*cos(th1)*sin(th2))/590295810358705651712.0+ (2110162899558835.0*v2*v2*sin(2.0*th1)*cos(th2)*cos(th3))/590295810358705651712.0 + (2110162899558835.0*v3*v3*sin(2.0*th1)*cos(th2)*cos(th3))/590295810358705651712.0 - (7357305309316421.0*v2*v2*sin(2.0*th1)*cos(th2)*sin(th3))/4722366482869645213696.0- (7357305309316421.0*v2*v2*sin(2.0*th1)*cos(th3)*sin(th2))/4722366482869645213696.0- (7357305309316421.0*v3*v3*sin(2.0*th1)*cos(th2)*sin(th3))/4722366482869645213696.0 - (7357305309316421.0*v3*v3*sin(2.0*th1)*cos(th3)*sin(th2))/4722366482869645213696.0 - (2110162899558835.0*v2*v2*sin(2.0*th1)*sin(th2)*sin(th3))/590295810358705651712.0- (2110162899558835.0*v3*v3*sin(2.0*th1)*sin(th2)*sin(th3))/590295810358705651712.0+ (209957596367.0*v1*v2*cos(2.0*th2)*sin(th1))/10000000000000.0 + (85865525619.0*v2*v3*cos(2.0*th2)*sin(th3))/20000000000000.0+ (85865525619.0*v2*v3*sin(2.0*th2)*cos(th3))/20000000000000.0 + (3812649803609637.0*v1*v2*sin(2.0*th2)*sin(th1))/75557863725914323419136.0 - (85865525619.0*v2*v2*cos(2.0*th1)*cos(2.0*th2)*sin(th3))/20000000000000.0 - (85865525619.0*v2*v2*cos(2.0*th1)*sin(2.0*th2)*cos(th3))/20000000000000.0 - (2833797679040417.0*v2*v3*cos(2.0*th2)*cos(2.0*th3))/18889465931478580854784.0 + (50567338383.0*v2*v3*cos(2.0*th2)*sin(2.0*th3))/20000000000000.0+ (50567338383.0*v2*v3*cos(2.0*th3)*sin(2.0*th2))/20000000000000.0+ (2833797679040417.0*v2*v3*sin(2.0*th2)*sin(2.0*th3))/18889465931478580854784.0 + (2833797679040417.0*v2*v2*cos(2.0*th1)*cos(2.0*th2)*cos(2.0*th3))/37778931862957161709568.0 + (2833797679040417.0*v3*v3*cos(2.0*th1)*cos(2.0*th2)*cos(2.0*th3))/37778931862957161709568.0 - (50567338383.0*v2*v2*cos(2.0*th1)*cos(2.0*th2)*sin(2.0*th3))/40000000000000.0 - (50567338383.0*v2*v2*cos(2.0*th1)*cos(2.0*th3)*sin(2.0*th2))/40000000000000.0 - (50567338383.0*v3*v3*cos(2.0*th1)*cos(2.0*th2)*sin(2.0*th3))/40000000000000.0 - (50567338383.0*v3*v3*cos(2.0*th1)*cos(2.0*th3)*sin(2.0*th2))/40000000000000.0 - (2833797679040417.0*v2*v2*cos(2.0*th1)*sin(2.0*th2)*sin(2.0*th3))/37778931862957161709568.0 - (2833797679040417.0*v3*v3*cos(2.0*th1)*sin(2.0*th2)*sin(2.0*th3))/37778931862957161709568.0 + (681534882286799.0*v1*v2*cos(th1)*cos(th2))/295147905179352825856.0- (50567338383.0*v2*v3*cos(2.0*th1)*cos(2.0*th2)*sin(2.0*th3))/20000000000000.0 - (50567338383.0*v2*v3*cos(2.0*th1)*cos(2.0*th3)*sin(2.0*th2))/20000000000000.0 - (2833797679040417.0*v2*v3*cos(2.0*th1)*sin(2.0*th2)*sin(2.0*th3))/18889465931478580854784.0+ (85865525619.0*v1*v2*cos(2.0*th2)*cos(th3)*sin(th1))/5000000000000.0 + (85865525619.0*v1*v3*cos(2.0*th2)*cos(th3)*sin(th1))/10000000000000.0+ (2110162899558835.0*v2*v3*sin(2.0*th1)*cos(th2)*cos(th3))/295147905179352825856.0- (7357305309316421.0*v2*v3*sin(2.0*th1)*cos(th2)*sin(th3))/2361183241434822606848.0- (7357305309316421.0*v2*v3*sin(2.0*th1)*cos(th3)*sin(th2))/2361183241434822606848.0- (85865525619.0*v1*v2*sin(2.0*th2)*sin(th1)*sin(th3))/5000000000000.0- (85865525619.0*v1*v3*sin(2.0*th2)*sin(th1)*sin(th3))/10000000000000.0- (2110162899558835.0*v2*v3*sin(2.0*th1)*sin(th2)*sin(th3))/295147905179352825856.0+ (50567338383.0*v1*v2*cos(2.0*th2)*cos(2.0*th3)*sin(th1))/10000000000000.0 + (50567338383.0*v1*v3*cos(2.0*th2)*cos(2.0*th3)*sin(th1))/10000000000000.0 - (85865525619.0*v2*v3*cos(2.0*th1)*cos(2.0*th2)*sin(th3))/20000000000000.0 - (85865525619.0*v2*v3*cos(2.0*th1)*sin(2.0*th2)*cos(th3))/20000000000000.0 + (2833797679040417.0*v1*v2*cos(2.0*th2)*sin(2.0*th3)*sin(th1))/9444732965739290427392.0 + (2833797679040417.0*v1*v2*cos(2.0*th3)*sin(2.0*th2)*sin(th1))/9444732965739290427392.0 + (2833797679040417.0*v1*v3*cos(2.0*th2)*sin(2.0*th3)*sin(th1))/9444732965739290427392.0 + (2833797679040417.0*v1*v3*cos(2.0*th3)*sin(2.0*th2)*sin(th1))/9444732965739290427392.0 - (50567338383.0*v1*v2*sin(2.0*th2)*sin(2.0*th3)*sin(th1))/10000000000000.0 - (50567338383.0*v1*v3*sin(2.0*th2)*sin(2.0*th3)*sin(th1))/10000000000000.0 - (7357305309316421.0*v1*v2*cos(th1)*cos(th2)*cos(th3))/2361183241434822606848.0- (7357305309316421.0*v1*v3*cos(th1)*cos(th2)*cos(th3))/2361183241434822606848.0- (2110162899558835.0*v1*v2*cos(th1)*cos(th2)*sin(th3))/295147905179352825856.0 - (2110162899558835.0*v1*v2*cos(th1)*cos(th3)*sin(th2))/295147905179352825856.0 - (2110162899558835.0*v1*v3*cos(th1)*cos(th2)*sin(th3))/295147905179352825856.0 - (2110162899558835.0*v1*v3*cos(th1)*cos(th3)*sin(th2))/295147905179352825856.0 + (2833797679040417.0*v2*v3*cos(2.0*th1)*cos(2.0*th2)*cos(2.0*th3))/18889465931478580854784.0 + (7357305309316421.0*v1*v2*cos(th1)*sin(th2)*sin(th3))/2361183241434822606848.0 + (7357305309316421.0*v1*v3*cos(th1)*sin(th2)*sin(th3))/2361183241434822606848.0;
    v31=(85865525619.0*v1*v1*sin(th3))/20000000000000.0 + (257596576857.0*v2*v2*sin(th3))/40000000000000.0 - (85865525619.0*v2*v2*sin(2.0*th2 - 2.0*th1 + th3))/80000000000000.0 - (85865525619.0*v2*v2*sin(2.0*th1 + 2.0*th2 + th3))/80000000000000.0 - (85865525619.0*v1*v1*sin(2.0*th2 + th3))/20000000000000.0 + (85865525619.0*v2*v2*sin(2.0*th1 + th3))/80000000000000.0 + (85865525619.0*v2*v2*sin(2.0*th2 + th3))/40000000000000.0 + (2833797679040417.0*v2*v2*cos(2.0*th2 - 2.0*th1 + 2.0*th3))/75557863725914323419136.0 + (2833797679040417.0*v2*v2*cos(2.0*th1 + 2.0*th2 + 2.0*th3))/75557863725914323419136.0 + (2833797679040417.0*v3*v3*cos(2.0*th2 - 2.0*th1 + 2.0*th3))/75557863725914323419136.0 + (2833797679040417.0*v3*v3*cos(2.0*th1 + 2.0*th2 + 2.0*th3))/75557863725914323419136.0 - (50567338383.0*v2*v2*sin(2.0*th2 - 2.0*th1 + 2.0*th3))/80000000000000.0 - (50567338383.0*v2*v2*sin(2.0*th1 + 2.0*th2 + 2.0*th3))/80000000000000.0 - (50567338383.0*v3*v3*sin(2.0*th2 - 2.0*th1 + 2.0*th3))/80000000000000.0 - (50567338383.0*v3*v3*sin(2.0*th1 + 2.0*th2 + 2.0*th3))/80000000000000.0 + (2833797679040417.0*v1*v1*cos(2.0*th2 + 2.0*th3))/18889465931478580854784.0 - (2833797679040417.0*v2*v2*cos(2.0*th2 + 2.0*th3))/37778931862957161709568.0- (2833797679040417.0*v3*v3*cos(2.0*th2 + 2.0*th3))/37778931862957161709568.0 - (85865525619.0*v2*v2*sin(2.0*th1 - th3))/80000000000000.0 - (50567338383.0*v1*v1*sin(2.0*th2 + 2.0*th3))/20000000000000.0 + (50567338383.0*v2*v2*sin(2.0*th2 + 2.0*th3))/40000000000000.0 + (50567338383.0*v3*v3*sin(2.0*th2 + 2.0*th3))/40000000000000.0 - (7357305309316421.0*v2*v2*cos(th2 - 2.0*th1 + th3))/9444732965739290427392.0 + (7357305309316421.0*v2*v2*cos(2.0*th1 + th2 + th3))/9444732965739290427392.0 - (7357305309316421.0*v3*v3*cos(th2 - 2.0*th1 + th3))/9444732965739290427392.0 + (7357305309316421.0*v3*v3*cos(2.0*th1 + th2 + th3))/9444732965739290427392.0 - (2110162899558835.0*v2*v2*sin(th2 - 2.0*th1 + th3))/1180591620717411303424.0 + (2110162899558835.0*v2*v2*sin(2.0*th1 + th2 + th3))/1180591620717411303424.0 - (2110162899558835.0*v3*v3*sin(th2 - 2.0*th1 + th3))/1180591620717411303424.0 + (2110162899558835.0*v3*v3*sin(2.0*th1 + th2 + th3))/1180591620717411303424.0 - (85865525619.0*v1*v3*sin(th1 + th3))/40000000000000.0 - (2833797679040417.0*v1*v2*cos(th1 + 2.0*th2 + 2.0*th3))/18889465931478580854784.0 - (2833797679040417.0*v1*v3*cos(th1 + 2.0*th2 + 2.0*th3))/18889465931478580854784.0 + (257596576857.0*v2*v3*sin(th3))/40000000000000.0 - (85865525619.0*v1*v2*sin(2.0*th2 - th1 + th3))/20000000000000.0 + (50567338383.0*v1*v2*sin(th1 + 2.0*th2 + 2.0*th3))/20000000000000.0 - (85865525619.0*v1*v3*sin(2.0*th2 - th1 + th3))/40000000000000.0 + (50567338383.0*v1*v3*sin(th1 + 2.0*th2 + 2.0*th3))/20000000000000.0 - (85865525619.0*v2*v3*sin(2.0*th2 - 2.0*th1 + th3))/80000000000000.0 - (85865525619.0*v2*v3*sin(2.0*th1 + 2.0*th2 + th3))/80000000000000.0 - (85865525619.0*v1*v3*sin(th1 - th3))/40000000000000.0 + (85865525619.0*v2*v3*sin(2.0*th1 + th3))/80000000000000.0 + (85865525619.0*v2*v3*sin(2.0*th2 + th3))/40000000000000.0 - (7357305309316421.0*v1*v2*cos(th1 + th2 + th3))/4722366482869645213696.0 - (7357305309316421.0*v1*v3*cos(th1 + th2 + th3))/4722366482869645213696.0 - (2110162899558835.0*v1*v2*sin(th1 + th2 + th3))/590295810358705651712.0 - (2110162899558835.0*v1*v3*sin(th1 + th2 + th3))/590295810358705651712.0 + (2833797679040417.0*v1*v2*cos(2.0*th2 - th1 + 2.0*th3))/18889465931478580854784.0 + (2833797679040417.0*v1*v3*cos(2.0*th2 - th1 + 2.0*th3))/18889465931478580854784.0 + (2833797679040417.0*v2*v3*cos(2.0*th2 - 2.0*th1 + 2.0*th3))/37778931862957161709568.0 + (2833797679040417.0*v2*v3*cos(2.0*th1 + 2.0*th2 + 2.0*th3))/37778931862957161709568.0- (50567338383.0*v1*v2*sin(2.0*th2 - th1 + 2.0*th3))/20000000000000.0 - (50567338383.0*v1*v3*sin(2.0*th2 - th1 + 2.0*th3))/20000000000000.0 - (50567338383.0*v2*v3*sin(2.0*th2 - 2.0*th1 + 2.0*th3))/40000000000000.0- (50567338383.0*v2*v3*sin(2.0*th1 + 2.0*th2 + 2.0*th3))/40000000000000.0- (2833797679040417.0*v2*v3*cos(2.0*th2 + 2.0*th3))/18889465931478580854784.0 - (85865525619.0*v2*v3*sin(2.0*th1 - th3))/80000000000000.0 + (50567338383.0*v2*v3*sin(2.0*th2 + 2.0*th3))/20000000000000.0- (7357305309316421.0*v1*v2*cos(th2 - th1 + th3))/4722366482869645213696.0 - (7357305309316421.0*v1*v3*cos(th2 - th1 + th3))/4722366482869645213696.0 - (7357305309316421.0*v2*v3*cos(th2 - 2.0*th1 + th3))/4722366482869645213696.0 + (7357305309316421.0*v2*v3*cos(2.0*th1 + th2 + th3))/4722366482869645213696.0 - (2110162899558835.0*v1*v2*sin(th2 - th1 + th3))/590295810358705651712.0 + (85865525619.0*v1*v2*sin(th1 + 2.0*th2 + th3))/20000000000000.0 - (2110162899558835.0*v1*v3*sin(th2 - th1 + th3))/590295810358705651712.0 + (85865525619.0*v1*v3*sin(th1 + 2.0*th2 + th3))/40000000000000.0 - (2110162899558835.0*v2*v3*sin(th2 - 2.0*th1 + th3))/590295810358705651712.0 + (2110162899558835.0*v2*v3*sin(2.0*th1 + th2 + th3))/590295810358705651712.0;
    //
    g11= 0.0;
    g21= -(3.0*g*(1314919.0*sin(th2 + th3) + 3497307.0*sin(th2)))/100000000.0;
    g31= -(3944757.0*g*sin(th2 + th3))/100000000.0;

    float M[9]={m11, m21, m31, m12, m22, m32, m13, m23, m33};
    float V[3]={v11, v21, v31};
    float G[3]={g11, g21, g31};
    //
    float M11= m11*a1;
    float M21= m21*a1;
    float M31= m31*a1;
    float M12= m12*a2;
    float M22= m12*a2;
    float M32= m32*a2;
    float M13= m13*a3;
    float M23= m23*a3;
    float M33= m33*a3;

    float M1=m11*a1+m12*a2+m13*a3;
    float M2=m21*a1+m22*a2+m23*a3;
    float M3=m31*a1+m32*a2+m33*a3;
    float tau1=M1+v11-g11;
    float tau2=M2+v21-g21;
    float tau3=M3+v31-g31;
    float tau[3]={tau1,tau2,tau3};

return tau[id-1];
}
