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

	string GetVehicleNumber() {
		return this->vehicle_number;
	}
};

class ParkingSpot {
private:
	int floor;
	Vehicle* automobile; //Vehicle number 
	ParkingSpotType spotType;

public:
	ParkingSpot(int floor, ParkingSpotType spotType) {
		this->floor = floor;
		this->spotType = spotType;
	};

	void Occupy(Vehicle* automobile) {
		this->automobile = automobile;
	}

	bool IsReserved() {
		return (automobile != nullptr);
	}

	ParkingSpotType GetSpotType() {
		return this->spotType;
	}

	void Release() {
		automobile = nullptr;
		return;
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

	void ReleaseParking(ParkingSpotType type, ParkingSpot* spot) {
		spot->Release();
		types_of_parking[type].push_back(spot);
	}

	~ParkingFloor() {
		for (auto it = types_of_parking.begin(); it != types_of_parking.end(); ++it) {
			for (auto ix = (*it).second.begin(); ix != (*it).second.end(); ++ix) {
				delete (*ix);
			}
		}
	}
	
};



class Station {
	int floor;
	static map<int, pair<ParkingFloor*, ParkingSpot*>> vehicle_ticket;
public:
	Station(int floor) {
		this->floor = floor;
	}

	int GetTicket(ParkingFloor* floor, ParkingSpot* spot) {
		srand(0);
		int ticket = int(rand() % 100000);
		
		while (vehicle_ticket.find(ticket) != vehicle_ticket.end()) {

			ticket = int(rand() % 100000);
		}
		vehicle_ticket[ticket] = make_pair(floor, spot);
		return int(ticket);
	}

	pair< ParkingFloor*, ParkingSpot*> ReturnTicket(int ticket) {
		if (vehicle_ticket.find(ticket) != vehicle_ticket.end()) {
			auto ret_val = vehicle_ticket[ticket];
			vehicle_ticket.erase(ticket);
			return ret_val;
		}
		return make_pair(nullptr, nullptr);
	}

	
};

map<int, pair<ParkingFloor*, ParkingSpot*>> Station::vehicle_ticket;

//Use singleton pattern
class ParkingLot {
private:
	vector<ParkingFloor*> all_floors;
	vector<Station*> all_stations;
	ParkingLot() {} //Private Constructor

public:
	static ParkingLot& getInstance() {
		static ParkingLot instance;
		return instance;
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

	int EnterLot(Vehicle* vech, ParkingType vehicle_type, bool handicapped){
		ParkingSpotType spot_type;
		int ticket;
		if (handicapped == true) {
			spot_type = ParkingSpotType::handicapped;
		}
		else {
			switch (vehicle_type) {
			case (ParkingType::Car):
				spot_type = ParkingSpotType::compact;
				break;

			case (ParkingType::Bus):
				spot_type = ParkingSpotType::large;
				break;

			case (ParkingType::Motorbike):
				spot_type == ParkingSpotType::motorbike;
				break;
			}
		}

		for (auto it = all_floors.begin(); it != all_floors.end(); ++it) {
			ParkingSpot* spot = (*it)->GetParkingSpots(spot_type);
			if (spot) {
				ticket = all_stations.back()->GetTicket(*it, spot);
				spot->Occupy(vech);
				break;
			}
		}
		return ticket;
	}

	bool ExitLot(int ticket) {
		auto station1 = all_stations.back();
		pair< ParkingFloor*, ParkingSpot*> p1 = station1->ReturnTicket(ticket);
		/*
		if (fl and spot) {
			auto spot_type = spot->GetSpotType();
			fl->ReleaseParking(spot_type, spot);
			return true;
		}
		else {
			return false;
		}
		*/
		return true;
	}

	~ParkingLot() {
	}
};



int main() {
	ParkingLot p1 =  p1.getInstance();
	Vehicle *v1 = new Vehicle("ABC", ParkingType::Car);
	p1.AddParking(4);
	int ticket = p1.EnterLot(v1, ParkingType::Car, false);
	p1.ExitLot(ticket);
	delete v1;
}