

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>


using namespace std;
//Demes klase
class Blob 
{
private : 
	int id;
	int size;
public :
	Blob()
	{
		
	}
	Blob()
	{
		size = 0;
	}

	void addCell() 
	{
		size++;
	}

	int getSize() const 
	{
		return size;
	}


};

//tinklelio klase
class Grid

{
private :
	const int N = 25;
	vector<vector<int>> cells; //langeliai
	vector<vector<bool>> visited; //aplankyti

	int numRows, numCols; //eiluciu sk ir stulpeliu sk
	 //Paieška į gylį (Depth-first search)
	int dfs(int row, int col)
	{
		int count = 1;
		visited[row][col] = true;

		

		// Patikrinkite visas gretimas langelius
		for (int i = row - 1; i <= row + 1; i++) {
			for (int j = col - 1; j <= col + 1; j++) {
				if (i >= 0 && i < numRows && j >= 0 && j < numCols && !visited[i][j] && cells[i][j] == 1) {
					count += dfs(i, j);
				}
			}
		}

		return count;
	}
public:
	Grid()
	{

	}
	Grid(const vector<string>& input) 
	{
		numRows = input.size();
		numCols = input[0].length();
		cells.resize(numRows, vector<int>(numCols));
		visited.resize(numRows, vector<bool>(numCols, false));

		// Tinklelio inicijacija
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				cells[i][j] = input[i][j] - '0';
			}
		}
	}
	//Surandame dydziausai deme
	int findLargestBlob()
	{
		int largestBlobSize = 0;

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (!visited[i][j] && cells[i][j] == 1) {
					Blob blob;
					int blobSize = dfs(i, j);
					largestBlobSize = max(largestBlobSize, blobSize);
				}
			}
		}

		return largestBlobSize;
	}
};

class InOutUtils {
public:
	

	

};
	static vector<string> readDataFromFile(string filename) 
	{
		vector<string> data;
		ifstream infile(filename);

		if (infile) 
		{
			string line;
			while (getline(infile, line)) 
			{
				data.push_back(line);
			}
		}
 else 
	{
  cerr << "ivyko klaida." << endl;

	}
		

return data;
	}

	

	static void writeDataToFile(int data, string filename) {
		ofstream outfile(filename);

		if (outfile) {
			outfile << data << endl;
		}
		else {
			cerr << "Klaida" << endl;
		}
	}

	static void printDataToConsole(vector<string> data) {
		for (string line : data) {
			cout << line << endl;
		}
	}
;



int main()
{

	auto start = chrono::steady_clock::now();


	chrono::time_point<std::chrono::system_clock> start, end;
	auto start = chrono::steady_clock::now();
	vector<Blob> blobs;
	vector<Grid> grid;

	int numCases;
	cin >> numCases;

	for (int i = 0; i < numCases; i++) {
		if (i > 0) {
			cout << endl; // isvesti atskiriame tuscia eilute
		}

		vector<string> input;
		string line;

		// skaitome inputa

		while (getline(cin, line)) {
			if (line.empty()) {
				break;
			}

			input.push_back(line);
		}

		Grid grid(input);
		int largestBlobSize = grid.findLargestBlob();
		cout << largestBlobSize << endl;

		auto end = chrono::steady_clock::now();
		chrono::duration<double> elapsed_seconds = end - start;
		cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";

			
	}

	return 0;
}




