#include <stdio.h>
#include <string.h>

//char *remove(char expression[], int length) {
//	//char *secondArr[30];
//	char *secondArr;
//	secondArr = (char*)malloc(length);
//	int iterator = 0;
//	for (int i = 0; i < length; i++) {
//		if (expression[i] != 0) {
//			secondArr[iterator] = expression[i];
//			iterator++;
//		}
//	}
//	return *secondArr;
//}

int valid(char expression[], int length, int start) {
	//char newArr[30];
	int exit = 1;
	while (exit != 0) {
		if (expression[start + 1] == opposite(expression[start])) {
			//char *newArr = remove(expression, length);
			char newArr[30];
			int iterator = 0;
			for (int i = 0; i < length; i++) {
				if (expression[i] != 0) {
					newArr[iterator] = expression[i];
					iterator++;
				}
			}
			valid(newArr, length - 2, start - 1);
		}
		else if (expression[start + 1] != 0) {
			valid(expression, length, start + 1);
		}
		else if (expression[start + 1] == 0) {
			for (int i = 0; i < length; i++) {
				if (expression[i] != 0) {
					exit = 0;
				}
				else {
					return 1;
				}
			}
		}
	}
	return 0;
}

int opposite(char toBeChecked) {
	if (toBeChecked == 40) {
		return 41;
	}
	else if (toBeChecked == 91) {
		return 93;
	}
	else if (toBeChecked == 123) {
		return 125;
	}
	return 0;
}


int main() {
	char expression[30]; //This will hold the value from the file when it is read in.
	int length; //This will be used to determine the length of the string from the file.
	FILE *fp; //This is the pointer to the file that will be read from.
	fopen_s(&fp, "expressions.txt", "r"); //This opens the file.
	if (fp != NULL) { //If the file is not empty
		while (fscanf_s(fp, "%30s", expression, sizeof(expression)) != EOF) { //This puts the input line by line in the expression[] while it is not EndOfFile
			length = 0; //Set the length to zero everytime so the length is accurate per line.
			for (int i = 0; i < 21; i++) {
				if (expression[i] > 0) {
					length++;
				}
			} //This for loop just determines the length to send to the function.
			int validResult = valid(expression, length, 0);
			//From here we'll make 1 true and 0 false or something of the sort.
			if (validResult == 1) {
				printf("%s", expression);
				printf("The expression is valid \n");
			}
			else if (validResult == 0) {
				printf("%s", expression);
				printf("The expression is INVALID \n");
			}
		}
	}

}



