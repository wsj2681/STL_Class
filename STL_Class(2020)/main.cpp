#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <functional>
#include <map>
using namespace std;

//random_device rd;
default_random_engine dre;//{ rd() };

// id Length 3~6 charactor
uniform_int_distribution<> idlength(3, 6);
uniform_int_distribution<> idchar('a', 'z');

// 0 : BreakOut, 1 : WorldChampionShip
normal_distribution<> playgametype(0, 1);

normal_distribution<> ndbreak(0, 2'905'887'026);
normal_distribution<> ndworld(0, 1'112'670'384);

//Player Count 10'0000
constexpr int PLAYERS_COUNT{ 10'0000 };

string filename{ "PlayerData.txt" };

class Player {
	string id{};

	//Score
	unsigned int breakout		{ 0 };
	unsigned int worldchampion	{ 0 };

	//Ranking
	int BreakRank	{ 0 };
	int worldRank	{ 0 };

	//Distribution
	float BreakDist		{ 0.f };
	float WorldDist		{ 0.f };
public:
	Player() {
		int len = idlength(dre);
		for (int i = 0; i < len; ++i) {
			id += idchar(dre);
		}
		breakout	  = static_cast<unsigned int>(roundl(ndbreak(dre)));
		worldchampion = static_cast<unsigned int>(roundl(ndworld(dre)));
	}

	~Player() {};

	string GetId()const {
		return id;
	}

	void PlayBreakOut() {
		unsigned int score =
			static_cast<unsigned int>(round(ndbreak(dre)));

		if (score >= breakout)
			breakout = score;
	}

	void PlayWorldChampionShip() {
		unsigned int score =
			static_cast<unsigned int>(round(ndworld(dre)));

		if (score >= worldchampion)
			worldchampion = score;
	}

	unsigned int GetBreakOutScore() const {
		return breakout;
	}

	unsigned int GetWorldChampionScore() const {
		return worldchampion;
	}

	int GetBreakOutRank()const {
		return BreakRank;
	}

	int GetWorldRank()const {
		return worldRank;
	}

	void SetBreakOutRank(int rank) {
		BreakRank = rank;
		BreakDist = static_cast<float>(rank) / PLAYERS_COUNT * 100.f;
	}
	void SetWorldRank(int rank) {
		worldRank = rank;
		WorldDist = static_cast<float>(rank) / PLAYERS_COUNT * 100.f;
	}

	void showBreakOut() const {
		cout << id
			<< "\t점수 -\t" << breakout 
			<< " 순위- " << BreakRank 
			<< "\t상위 " << BreakDist << "%" << endl;

	}
	void ShowWorldChampionShip()const {
		cout << id
			<< "\t점수 -\t" << worldchampion 
			<< " 순위- " << worldRank 
			<< "\t상위 " << WorldDist << "%" << endl;
	}
	friend ostream& operator<<(ostream&, const Player&);
	friend istream& operator>>(istream&, Player&);
};

ostream& operator<<(ostream& os, const Player& p) {
	os << p.id << " " << p.breakout << " " << p.BreakRank
		<< " " << p.worldchampion << " " << p.worldRank;
	return os;
}

istream& operator>>(istream& is, Player& p) {
	is >> p.id >> p.breakout >> p.BreakRank >> p.worldchampion >> p.worldRank;
	return is;
}

void Mapping(const vector<Player>& players, map<string, Player>& mapplayers);
void MakeData(vector<Player>&);
void PlayGame(vector<Player>&);
void RankingSet(vector<Player>&);
void SaveGame(const vector<Player>&);

int main() {

	ifstream in(filename, ios::binary);
	vector<Player> players;
	players.reserve(PLAYERS_COUNT);


	//Can't found
	if (!in.is_open()) {
		//Initializing File
		cout << "초기 데이터 생성" << endl << endl;
		MakeData(players);
	}

	//Load Data File
	players = { istream_iterator<Player>(in), istream_iterator<Player>() };

	map<string, Player> mapplayers;
	
	Mapping(players, mapplayers);

	//Over one Season
	PlayGame(players);

	//Player Ranking Set
	RankingSet(players);

	//Find Player
	string input{};
	cout << "찾고싶은 id 를 입력하세요. : ";
	cin >> input;

	//Search BreakOut Rank
	{
		vector<Player> foundBreakOut;

		vector<Player>::iterator findB = find_if(players.begin(), players.end(), [input](const Player& p) {
			return input == p.GetId();
		});

		foundBreakOut.emplace_back(*find_if(players.begin(), players.end(), [findB](const Player& p) {
			return findB->GetBreakOutRank() - 1 == p.GetBreakOutRank();
		}));

		foundBreakOut.emplace_back(*findB);

		foundBreakOut.emplace_back(*find_if(players.begin(), players.end(), [findB](const Player& p) {
			return findB->GetBreakOutRank() + 1 == p.GetBreakOutRank();
		}));

		cout << endl << "\t\t떼탈출" << endl << endl;
		for (const auto& i : foundBreakOut)
			i.showBreakOut();
	}
	//TODO:인덱스 오류
	//while (true)
	//{
	//	auto p = mapplayers.find(input);
	//	if (p != mapplayers.find.end())
	//		p->second.showBreakOut();

	//}

	//Search WorldChampionShip Rank
	{
		vector<Player> foundWorld;

		vector<Player>::iterator findW = find_if(players.begin(), players.end(), [input](const Player& p) {
			return input == p.GetId();
		});

		foundWorld.emplace_back(*find_if(players.begin(), players.end(), [findW](const Player& p) {
			return findW->GetWorldRank() - 1 == p.GetWorldRank();
		}));

		foundWorld.emplace_back(*findW);

		foundWorld.emplace_back(*find_if(players.begin(), players.end(), [findW](const Player& p) {
			return findW->GetWorldRank() + 1 == p.GetWorldRank();
		}));

		cout << endl << "\t\t월드챔피언쉽" << endl << endl;
		for (const auto& i : foundWorld)
			i.ShowWorldChampionShip();
	}
	/*for (const auto& i : players)
		i.showBreakOut();*/
	SaveGame(players);

	size_t filesize = filesystem::file_size(filename);

	cout << filesize << endl;
}

void Mapping(const vector<Player>& players, map<string, Player>& mapplayers) {
	
}

void MakeData(vector<Player>& players) {
	for (int i = 0; i < PLAYERS_COUNT; ++i)
		players.emplace_back(Player());

	SaveGame(players);
}

void PlayGame(vector<Player>& players) {
	for (auto& i : players)
		if (playgametype(dre))
			i.PlayBreakOut();
		else
			i.PlayWorldChampionShip();
}

//TODO: write()함수 사용해서 파일로 보내기
void SaveGame(const vector<Player>& players) {
	ofstream out(filename, ios::binary);

	for (const auto& i : players)
		out << i << endl;
	cout << filename << " 저장 완료" << endl << endl;
}

void RankingSet(vector<Player>& players) {

	//WorldChampionShip Ranking Set
	{
		sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
			return a.GetWorldChampionScore() > b.GetWorldChampionScore();
		});

		for (int i = 0; i < players.size(); ++i)
			players[i].SetWorldRank(i + 1);
	}

	//BreakOut Ranking Set
	{
		sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
			return a.GetBreakOutScore() > b.GetBreakOutScore();
		});

		for (int i = 0; i < players.size(); ++i)
			players[i].SetBreakOutRank(i + 1);
	}
}