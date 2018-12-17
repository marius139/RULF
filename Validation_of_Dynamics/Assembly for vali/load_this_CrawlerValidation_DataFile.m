% Simscape(TM) Multibody(TM) version: 6.0

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(7).translation = [0.0 0.0 0.0];
smiData.RigidTransform(7).angle = 0.0;
smiData.RigidTransform(7).axis = [0.0 0.0 0.0];
smiData.RigidTransform(7).ID = '';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [28.583183278987455 97.387491151588478 132.20308440440925];  % mm
smiData.RigidTransform(1).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(1).axis = [1 0 0];
smiData.RigidTransform(1).ID = 'B[Link1-3:-:Link2-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [28.583183278987406 97.387491151588449 132.20308440440925];  % mm
smiData.RigidTransform(2).angle = 3.1415926535897922;  % rad
smiData.RigidTransform(2).axis = [1 1.4854949106603363e-31 2.7279053628512225e-16];
smiData.RigidTransform(2).ID = 'F[Link1-3:-:Link2-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [169.4589592262096 263.3091032162518 129.37108438381026];  % mm
smiData.RigidTransform(3).angle = 3.1415926535897922;  % rad
smiData.RigidTransform(3).axis = [1 2.0301859489548864e-31 4.3026563215087248e-16];
smiData.RigidTransform(3).ID = 'B[Link2-1:-:Link3NEW2-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [-115.57078846311524 370.60136109184543 25.82456578439394];  % mm
smiData.RigidTransform(4).angle = 1.7653223215496907;  % rad
smiData.RigidTransform(4).axis = [-0.40247833783582126 -0.4024783378358352 0.82220579853575448];
smiData.RigidTransform(4).ID = 'F[Link2-1:-:Link3NEW2-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [28.565183285787445 40.727491159388485 104.38508441440923];  % mm
smiData.RigidTransform(5).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(5).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(5).ID = 'B[Link1-3:-:Base.SLDASM-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [-5.6209218265733716 274.93687443273274 223.43558885187412];  % mm
smiData.RigidTransform(6).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(6).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(6).ID = 'F[Link1-3:-:Base.SLDASM-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [7.5511442995132745 -195.76734789287192 -43.035588851874138];  % mm
smiData.RigidTransform(7).angle = 0;  % rad
smiData.RigidTransform(7).axis = [0 0 0];
smiData.RigidTransform(7).ID = 'RootGround[Base.SLDASM-1]';


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(4).mass = 0.0;
smiData.Solid(4).CoM = [0.0 0.0 0.0];
smiData.Solid(4).MoI = [0.0 0.0 0.0];
smiData.Solid(4).PoI = [0.0 0.0 0.0];
smiData.Solid(4).color = [0.0 0.0 0.0];
smiData.Solid(4).opacity = 0.0;
smiData.Solid(4).ID = '';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 0.22800000000000001;  % kg
smiData.Solid(1).CoM = [28.582957740285682 74.651340671551026 104.7787142982849];  % mm
smiData.Solid(1).MoI = [169.32731336237669 104.36197449507746 149.82146080994016];  % kg*mm^2
smiData.Solid(1).PoI = [-2.934033300852648 0.0046662964490011734 -0.031812697060705192];  % kg*mm^2
smiData.Solid(1).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = 'Link1*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 2.484;  % kg
smiData.Solid(2).CoM = [-5.6209172589448562 225.97900220446382 226.90439763164522];  % mm
smiData.Solid(2).MoI = [11842.925293294091 11796.861189617668 11641.036378263016];  % kg*mm^2
smiData.Solid(2).PoI = [-177.5879128338542 0.00019733701613978519 -0.00024009354198281557];  % kg*mm^2
smiData.Solid(2).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = 'Base.SLDASM*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 0.22800000000000001;  % kg
smiData.Solid(3).CoM = [138.43589754801727 228.18151143509283 104.49362752930682];  % mm
smiData.Solid(3).MoI = [493.28655581778679 397.38776500016456 810.24270690681294];  % kg*mm^2
smiData.Solid(3).PoI = [-1.7456456404431979 -1.4854591103638486 -381.74683501062805];  % kg*mm^2
smiData.Solid(3).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = 'Link2*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(4).mass = 0.30299999999999999;  % kg
smiData.Solid(4).CoM = [-208.0130884731804 325.6361419061044 -51.355605423333031];  % mm
smiData.Solid(4).MoI = [394.70099219303387 527.09932424397846 326.40455892385876];  % kg*mm^2
smiData.Solid(4).PoI = [-119.97930969493844 -145.39283386388055 -94.669157221907426];  % kg*mm^2
smiData.Solid(4).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(4).opacity = 1;
smiData.Solid(4).ID = 'Link3NEW2*:*Default';


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(3).Rz.Pos = 0.0;
smiData.RevoluteJoint(3).ID = '';

smiData.RevoluteJoint(1).Rz.Pos = -40.411898544838685;  % deg
smiData.RevoluteJoint(1).ID = '[Link1-3:-:Link2-1]';

smiData.RevoluteJoint(2).Rz.Pos = -160.6856911331187;  % deg
smiData.RevoluteJoint(2).ID = '[Link2-1:-:Link3NEW2-1]';

smiData.RevoluteJoint(3).Rz.Pos = -89.928089125088064;  % deg
smiData.RevoluteJoint(3).ID = '[Link1-3:-:Base.SLDASM-1]';

