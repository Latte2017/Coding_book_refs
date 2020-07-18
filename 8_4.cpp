/*
Design a parking lot
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<deque>
using namespace std;

enum class ParkingType {
	Bus,
	Motorbike,
	Car
};


enum class ParkingSpotType {
	handicapped,
	compact,
	large,
	motorbike
};

class Vehicle {
private:
	string vehicle_number;
	ParkingType type;
	string parking_number;
public:
	Vehicle(string vehicle_number, ParkingType type) {
		this->vehicle_number = vehicle_number;
		this->type = type;
	}
};

class ParkingSpot {
private:
	int floor;
	string vehicle_number; //Vehicle number 
	ParkingSpotType spotType;

public:
	ParkingSpot(int floor, ParkingSpotType spotType) {
		this->floor = floor;
		this->spotType = spotType;
	};

	void Occupy(string vehicle_number) {
		this->vehicle_number = vehicle_number;
	}

	bool IsReserved(){
		return !vehicle_number.empty();
	}
};


class ParkingFloor {
private:
	int floor;
	map<ParkingSpotType, deque<ParkingSpot*>> types_of_parking;
	
public:

	ParkingFloor(int floor) {
		this->floor = floor;
	}

	void AddParking(vector<pair<ParkingSpotType, int>> park){
		for (auto it = park.begin(); it != park.end(); ++it) {
			for (auto iter1 = 0; iter1 < (*it).second; ++iter1) {
				types_of_parking[(*it).first].push_back(new ParkingSpot(floor, (*it).first));
			}
		}
	}

	ParkingSpot* GetParkingSpots(ParkingSpotType type){
		if (types_of_parking[type].size() > 0) {
			auto ret_val = types_of_parking[type].front();
			types_of_parking[type].pop_front();
			return ret_val;
		}
		else {
			return nullptr;
		}
	}
	
};



class Station {
	int floor;
	static map<int, Vehicle*> vehicle_ticket;
public:
	Station(int floor) {
		this->floor = floor;
	}

	int GetTicket(Vehicle* vehicle_id) {
		srand(0);
		int ticket = int(rand() % 100000);
		
		while (vehicle_ticket.find(ticket) != vehicle_ticket.end()) {
			ticket = int(rand() % 100000);
		}
		vehicle_ticket[ticket] = vehicle_id;
		return int(ticket);
	}

	bool ReturnTicket(int ticket) {
		if (vehicle_ticket.find(ticket) != vehicle_ticket.end()) {
			vehicle_ticket.erase(ticket);
			return true;
		}
		return false;
	}
};

//Initialize the pointer to null
ParkingLot* ParkingLot::instance = nullptr;

//Use singleton pattern
class ParkingLot {
private:
	static ParkingLot* instance;
	vector<ParkingFloor*> all_floors;
	vector<Station*> all_stations;
	ParkingLot() {} //Private Constructor

public:
	static ParkingLot* getInstance() {
		if (!instance) {
			instance = new ParkingLot;
			return instance;
		}
	}

	void AddParking(int num_floors, int num_spots=10) {
		vector<pair<ParkingSpotType, int>> floor_map;
		floor_map.push_back({ ParkingSpotType::compact, 4 });
		floor_map.push_back({ ParkingSpotType::large, num_spots-2 });
		floor_map.push_back({ ParkingSpotType::motorbike, num_spots-2 });
		floor_map.push_back({ ParkingSpotType::handicapped, num_spots-2 });
		for (auto it = 0; it != num_floors; ++it) {
			all_stations.push_back(new Station(it));
			all_floors.push_back(new ParkingFloor(it));
			all_floors.back()->AddParking(floor_map);
		}
	}
	
	void AddStation(int num_stations, int floor) {
		all_stations.push_back(new Station(floor));
	}

	void IssueTicket(Vehicle vech, ParkingType vehicle_type, bool handicapped){
		ParkingSpotType spot_type;
		if (handicapped == true) {
			spot_type = ParkingSpotType::handicapped;
		}
		else {
			switch (vehicle_type) {
			case (ParkingType::Car):
				spot_type = ParkingSpotType::compact;

			case (ParkingType::Bus):
				spot_type = ParkingSpotType::large;


			case (ParkingType::Motorbike):
				spot_type == ParkingSpotType::motorbike;
			}
		}

		for (auto it = all_floors.begin(); it != all_floors.end(); ++it) {
			if ((*it)->GetParkingSpots(spot_type)) {

			}
		}
	}
};





