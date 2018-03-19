#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include <sstream>
#include <iterator>
#include <fstream>

using namespace std;

string findNumberOfCityGoneThroughByGbus(const string&,
                                      const vector<int>&);

int main()
{
    ofstream outputFile;
    outputFile.open("output.txt");

    string input;

    // First valid data read from std::in is number of test cases.
    getline(cin, input);
    int numberOfTestCases = stoi(input);
    for (int i = 0; i < numberOfTestCases; ++i)
    {
        // Parsing data for each test case
        getline(cin, input);
        int numberOfGbuses = stoi(input);

        string allGbuses;
        getline(cin, allGbuses);

        getline(cin, input);
        int numberOfSearchedCities = stoi(input);
        vector<int> allSearchedCities(numberOfSearchedCities);
        for (int j = 0; j < numberOfSearchedCities; ++j)
        {
            getline(cin, input);
            allSearchedCities[j] = stoi(input);
        }

        //assert(allCities.size() == numberOfCities);

        getline(cin, input);
        if (input.empty())
        {
            // Reach the break line, process
            string output = "Case #" + to_string(i) + ":";
            output += findNumberOfCityGoneThroughByGbus(allGbuses, allSearchedCities) + "\n";
            //cout << output;
            outputFile << output;
        }
    }

    outputFile.close();
    return 0;
}

string findNumberOfCityGoneThroughByGbus(const string& t_allGbuses,
                                      const vector<int>& t_allSearchedCities)
{
    string result;
    // Parsing the t_allGbuses to two ends of each gbus.
    // 15 25 30 35 45 50 10 20
    // Two ends of the first gbus is 15 and 25.
    // t_allSearchedCities = {15, 25}

    vector<string> allCoveredCities;
    istringstream issAllGBuses(t_allGbuses);
    copy(istream_iterator<string>(issAllGBuses),
         istream_iterator<string>(),
         back_inserter(allCoveredCities));

    for (auto const &searchedCity : t_allSearchedCities)
    {
        int counter = 0;
        uint size = static_cast<uint> (allCoveredCities.size());
        for(uint i = 0; i < size; i = i + 2)
        {
            if (searchedCity >= stoi(allCoveredCities[i]) &&
                    searchedCity <= stoi(allCoveredCities[i + 1]))
            {
                counter ++;
            }
        }

        //cout << searchedCity << ": " << counter << endl;
        result += " " + to_string(counter);
    }

    return result;
}
