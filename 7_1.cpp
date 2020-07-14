/*
Questions from 6th edition

Design a deck of cards.

Explain how you would sub class it for backjack


https://www.geeksforgeeks.org/design-data-structuresclasses-objectsfor-generic-deck-cards/

*/

#include<string>
#include<vector>
#include<set>


using namespace std;

enum class enum_suits
{
	SPADE,
	DIAMOND,
	HEART,
	CLUB
};


class Cards {
private:
	int val =0;
	enum_suits s1;
public:
	const virtual enum_suits GetSuit() {
		return s1;
	}

	const virtual int GetVal() {
		return val;
	}

	virtual Cards*  Card(int val, enum_suits suit1) {
		this->val = val;
		this->s1 = suit1;
		return this;
	}

	void virtual SetVal(int val) {
		this->val = val;
	}
};


class Deck:public Cards {
private:
	vector<Cards*> num_cards[52];
	static int num_of_spades, num_of_diamonds, num_of_hearts, num_of_clubs;
public:
	virtual Cards*  Card(int vl, enum_suits suits) {
		if (suits == enum_suits::CLUB){
			if (num_of_clubs <= 0) {
				return nullptr;
			}
			else {
				num_of_clubs--;
			}
		}
		else if (suits == enum_suits::DIAMOND){
			if (num_of_diamonds <= 0) {
				return nullptr;
			}
			else {
				num_of_diamonds--;
			}
		}
		else if (suits == enum_suits::HEART){
			if (num_of_hearts <= 0) {
				return nullptr;
			}
			else {
				num_of_hearts--;
			}
		}
		else if (suits == enum_suits::SPADE){
			if (num_of_spades <= 0) {
				return nullptr;
			}
			else {
				num_of_spades--;
			}
		}
		num_cards->push_back(Cards::Card(vl, suits));
		
	}
	
	
};


int Deck::num_of_clubs = 13;
int Deck::num_of_diamonds = 13;
int Deck::num_of_hearts = 13;
int Deck::num_of_spades = 13;

class BlackJackCard : public Deck {
public:
	const virtual int GetVal() {
		int val = Deck::GetVal();
		if (val < 10) {
			return val;
		}
		else if (val == 13) {
			return 11;
		}
		return 10;
	}

	const virtual enum_suits GetSuit() {
		return Deck::GetSuit();
	}

	BlackJackCard(int val, enum_suits suit) {
		
	};

	virtual void SetVal(int val) {
		Cards::SetVal(val);
	}
	
};

class Player {
private:
	int id;
	float bet;
	set<int> points;
	vector<BlackJackCard*> black_jack_player_cards;
	void GetCard() {
		int card_val = rand() % 13;
		enum_suits set_suit = enum_suits(rand() % 4);
		auto black_jack_card = new BlackJackCard(card_val, set_suit);
		if (points.empty() and black_jack_card->GetVal() == 1 ) {
			black_jack_card->SetVal(11);
			black_jack_player_cards.push_back(black_jack_card);
			points.insert(black_jack_card->GetVal());
		}
		else {
			black_jack_player_cards.push_back(black_jack_card);
			points.insert(black_jack_card->GetVal());
		}
	}

public:
	Player() {
		//Player gets 2 cards in the beginning
		GetCard();
		GetCard();
	}

	vector<BlackJackCard*> GetAllCards() {
		return black_jack_player_cards;
	}

	void AddCard() {
		GetCard();
	}

	int GetScore() {
		int player_score = 0;

		for (auto it = points.begin(); it != points.end(); ++it) {
			player_score += *it;
		}
		return player_score;
	}


	virtual ~Player() {
		for (auto it = black_jack_player_cards.begin(); it != black_jack_player_cards.end(); ++it) {
			delete* it;
		}
	}
};


class BlackJack {
private:
	int num_of_players = 0;
	vector<Player*> players;

	void Hit(Player* p1) {
		p1->AddCard();
	}
public:
	int StartGame(int num_of_players) {
		//dealer is the last
		for (auto it = 0; it < num_of_players+1; ++it) {
			players.push_back(new Player());
		}
	}

	



};

int main() {
	BlackJackCard b1(13, enum_suits::CLUB);
	enum_suits suit =  b1.GetSuit();
}