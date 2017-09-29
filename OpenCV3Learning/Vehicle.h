#pragma once
class Vehicle
{
public:
	virtual double weight() const = 0;
	virtual void start() = 0;
	virtual Vehicle* copy() const = 0;
	virtual ~Vehicle() {};
};

class RoadVehicle:public Vehicle
{
public:
	virtual double weight() const;
	virtual void start();
	virtual Vehicle* copy() const;
private:

};

class AutoVehicle :public Vehicle
{
public:
	virtual double weight() const;
	virtual void start();
	virtual Vehicle* copy() const;
private:

};

class AircraftVehicle :public Vehicle
{
public:
	virtual double weight() const;
	virtual void start();
	virtual Vehicle* copy() const;
private:

};

class HelicopterVehicle :public Vehicle
{
public:
	virtual double weight() const;
	virtual void start();
	virtual Vehicle* copy() const;
private:

};


//¥˙¿Ì¿‡


class VehicleSurrogate
{
public:
	VehicleSurrogate();
	VehicleSurrogate(Vehicle&);
	~VehicleSurrogate();
	VehicleSurrogate(const VehicleSurrogate&);
	VehicleSurrogate& operator=(const VehicleSurrogate&);
	double weight() const;
	void start();
private:
	Vehicle* vp;
};