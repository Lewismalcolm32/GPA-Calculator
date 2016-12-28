#include <iostream>
#include <string>
#include <vector>



std::vector<float> combineTwoVectors(const std::vector<float>& firstVector, const std::vector<float>& secondVector){//Assume they are of the same size
	if (firstVector.size() != secondVector.size()) {
		std::cerr << "Something went wrong!" << std::endl;
		std::vector<float> nullValue(-1);
		return nullValue;
	}
	std::vector<float> thirdVector;
	for (size_t ind = 0; ind < firstVector.size(); ++ind){
		thirdVector.push_back(firstVector[ind] * secondVector[ind]);
	}
	return thirdVector;
}

float addVectorValuesTogether(const std::vector<float>& aVector){
	float x = 0;
	for (float aVectorValue : aVector){
		x += aVectorValue;
	}
	return x;
}


float convertLetterGradeToNumberGrade(const std::string letterGrade){
	float numericGrade;

	if (letterGrade == "A"){
		numericGrade = 4.0;
	}
	else if (letterGrade == "B"){
		numericGrade = 3.0;
	}
	else if (letterGrade == "C"){
		numericGrade = 2.0;
	}
	else if (letterGrade == "D"){
		numericGrade = 1.0;
	}
	else if (letterGrade == "A-"){
		numericGrade = 3.7;
	}
	else if (letterGrade == "B-"){
		numericGrade = 2.7;
	}
	else if (letterGrade == "C-"){
		numericGrade = 1.7;
	}
	else if (letterGrade == "B+"){
		numericGrade = 3.3;
	}
	else if (letterGrade == "C+"){
		numericGrade = 2.3;
	}
	else if (letterGrade == "D+"){
		numericGrade = 1.3;
	}
	else if (letterGrade == "F"){
		numericGrade = 0.0;
	}
	else{ std::cout << "Something went wrong.\n"; numericGrade = -1.0; }

	return numericGrade;
}


void printOutVector(std::vector<float> someVector){
	for (size_t ind = 0; ind<someVector.size(); ++ind){
		std::cout << someVector[ind] << std::endl;
	}
	//std::cout << someVector[0] << std::endl;
}


float GPAcalculator(){
	std::vector<float> credits;
	std::vector<float> numericGrades;
	std::vector<std::string> letterGrades;
	float credit(0);
	//float numericGrade;
	std::string letterGrade;
	int count;

	std::cout << "How many entries will there be?" << std::endl;
	std::cin >> count;
	std::cout << "\n";
	while (count){
		std::cout << "Please enter credits for individual class: ";
		std::cin >> credit;
		credits.push_back(credit);
		std::cout << "Please enter letter grade received for respective credit hour: ";
		std::cin >> letterGrade;
		letterGrades.push_back(letterGrade);
		float numericGrade = convertLetterGradeToNumberGrade(letterGrade);
		numericGrades.push_back(numericGrade);
		//char answer;
		/*std::cout << "\n\nAre these all the inputs?\nEnter 'Y' for yes, or 'N' for no." << std::endl;
		std::cin >> answer;
		if (answer == 'n'){ std::cout << "\n"; GPAcalculator(); }*/
		--count;
	}


	float creditsAttempted(0);
	for (float creditHour : credits){
		creditsAttempted += creditHour;
	}

	std::cout << "\nWhat you entered:" << std::endl;
	for (size_t ind = 0; ind < letterGrades.size(); ++ind){
		std::cout << "An " << letterGrades[ind] << " for the " << credits[ind] << " credit course." << std::endl;
	}
	std::cout << std::endl;
	//printOutVector(credits);
	/*std::cout << std::endl;
	std::cout << "What you entered in for grades earned:" << std::endl;
	printOutVector(numericGrades);*/


	return  (addVectorValuesTogether(combineTwoVectors(credits, numericGrades)) / creditsAttempted);


}



int main(){
	std::cout << "\nCalculated GPA: " << GPAcalculator();
	std::cout << std::endl;
	system("pause");
}