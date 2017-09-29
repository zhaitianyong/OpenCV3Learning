#include "stdafx.h"
#include "Vehicle.h"
#include <iostream>

using namespace std;

#pragma region AutoVehicle

double AutoVehicle::weight() const
{
	cout << "AutoVehicle weight" << endl;
	return 1.0;
}
void AutoVehicle::start()
{
	cout << "AutoVehicle start" << endl;
}
Vehicle* AutoVehicle::copy() const
{
	return  new AutoVehicle(*this);
}


#pragma endregion

#pragma region RoadVehicle
double RoadVehicle::weight() const
{
	cout << "RoadVehicle weight" << endl;
	return 1.0;
}
void RoadVehicle::start()
{
	cout << "RoadVehicle start" << endl;
}
Vehicle* RoadVehicle::copy() const
{
	return  new RoadVehicle(*this);
}
#pragma endregion

#pragma region AircraftVehicle
double AircraftVehicle::weight() const
{
	cout << "AircraftVehicle weight" << endl;
	return 1.0;
}
void AircraftVehicle::start()
{
	cout << "AircraftVehicle start" << endl;
}
Vehicle* AircraftVehicle::copy() const
{
	return  new AircraftVehicle(*this);
}
#pragma endregion

#pragma region HelicopterVehicle
double HelicopterVehicle::weight() const
{
	cout << "HelicopterVehicle weight" << endl;
	return 1.0;
}
void HelicopterVehicle::start()
{
	cout << "AircraftVehicle start" << endl;
}
Vehicle* HelicopterVehicle::copy() const
{
	return  new HelicopterVehicle(*this);
}

#pragma endregion

#pragma region VehicleSurrogate
VehicleSurrogate::VehicleSurrogate():vp(0) {}

VehicleSurrogate::VehicleSurrogate(Vehicle& v)  { //这地方是否有问题？？ 需要去掉const吧
	vp = v.copy();
	cout << "VehicleSurrogate" << endl;
	printf("%x\n",vp);
}

VehicleSurrogate::~VehicleSurrogate() {
	delete vp;
}

VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate& v)
{
	vp = v.vp ? v.vp->copy():0;
}

VehicleSurrogate& VehicleSurrogate::operator=(const VehicleSurrogate& v)
{
	if (this!=&v)
	{
		delete vp;
		vp = v.vp ? v.vp->copy() : 0;
	}
	return *this;
}

double VehicleSurrogate::weight() const {
	if (vp==0)
	{
		throw "empty";
	}

	return vp->weight();

}

void VehicleSurrogate::start()
{
	if (vp==0)
	{
		throw "empty";
	}
	vp->start();
}

#pragma endregion 