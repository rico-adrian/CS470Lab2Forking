#include <iostream> 
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include <string> 
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char **arg) {

	if ((arg[1] != NULL) && (arg[1] == '\0')) {
		printf("c is empty\n");
	}
	if(arg[1]==NULL) {
		cout<<"Please enter a file name"<<endl;
		return 0;
	}
   char list[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   char list2[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char str[80];
	string text;
	int freq[128];
	strcpy(str, arg[1]);
	strcat(str, ".txt");
	cout << endl;
	cout << "opening " << arg[1] << " File " << endl;
	FILE* inputFile;
	char mychar;
	for (int k = 0; k < 128; k++)
	{
		freq[k] = 0;
	}
	
	for(int i=0;i<26;i++) {
		
		inputFile = fopen(arg[1], "r");
		if (!inputFile)
		{
		cout << "File does not exist." << endl;
		return 1;
		}
      pid_t pid = fork();
		if (pid == 0)
		{
			mychar = fgetc(inputFile);
			while (mychar != EOF)
			{
				if (mychar==list[i]||mychar==list2[i]) {
               freq[i]++;
            }
				mychar = fgetc(inputFile);
			}
         cout<<"process ID is equal to "<<getpid()<<endl;
         cout<<"frequency for letter "<<list[i]<<" and "<<list2[i]<<" is "<<freq[i];
			cout << endl;
			//inFile.close();
			_exit(0);
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
      }
	
	return 0;
}