#include "iostream"
#include "fstream"
#include "vector"
#include "srtparser.h"

using namespace std;
int main() {
	cout << "Welcome to SRT --> TXT." << endl << "Enter Subtitle File Path: ";
	string File;
	cin >> File;
	SubtitleParserFactory *subParserFactory = new SubtitleParserFactory(File);
	SubtitleParser *parser = subParserFactory->getParser();
	
	ofstream myfile;
	myfile.open ("SUB.txt");

	vector<SubtitleItem*> sub = parser->getSubtitles();
	for (int i = 0; i < sub.size(); i++) 
	{
		myfile << sub.at(i) -> getDialogue() << "\n";
	}
	myfile.close();
	system("start notepad SUB.txt");
}
