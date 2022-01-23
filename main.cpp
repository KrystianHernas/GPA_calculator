#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <iomanip>

float calculateGPA(std::vector < std::map <float, float> > grades);
std::vector < std::map <float, float> > lectures();

int main()
{
	//vector stores data about lectures. First element: Credit, second: Grade
	calculateGPA(lectures());
	return 0;
}

std::vector < std::map <float, float> > lectures() {
	std::vector < std::map <float, float> > grades; int amountOfLectures; float waga = 0.0f, ocena = 0.0f;
	std::cout << std::endl << "From how many lectures do you want to calculate GPA: " << std::endl;
	std::cin >> amountOfLectures;	grades.resize(amountOfLectures);
	for (int i = 0; i < amountOfLectures; i++) {
		std::cout << "Enter Credit for a lecture: " << std::endl; std::cin >> waga;
		std::cout << "Enter Grade for a lecture: " << std::endl; std::cin >> ocena;
		grades[i].insert(std::pair<float, float>(waga, ocena));
		//option for cout map
		//for (const auto& j : grades[i]) {
		//	std::cout << j.first; std::cout << j.second;
		//}
	};
	return grades;
}

float calculateGPA(std::vector <std::map <float, float> > grades) {
	float GPA = 0.0f, licznik = 0.0f, mianownik = 0.0f;
	for (int i = 0; i < grades.size(); i++) {
		for (const auto& j : grades[i]) {
			licznik += j.first * j.second;
			mianownik += j.first;
		}
	}
	GPA = (licznik / mianownik);
	std::cout << std::setprecision(3) << GPA << std::endl;
	return GPA;
};