// Dhruv Jain
// 12/6/20
// Binary tree




#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <math.h>
#include <iomanip>



using namespace std;

int sortheap(int *,int,int); //method to sort a perticular element into its corrct position in the array

void printtree(int *, int); //method to print the parents and thier children in sentence fomat

void printtreeshape(int *, int); //method to print the tree in shape form

int main(){
  cout << "Would you like to read in from a file, or from terminal?" << endl;
  char input[20];
  bool done = false;
  bool fileread = false;
  int totalelements = 0;

  while (done == false){
    cout << "Would you like to read in from a file, or from terminal?" << endl;
    cin >> input;
    if(strcmp(input, "file") == 0){
      fileread = true;
      done = true;
    }
    else if(strcmp(input, "terminal") == 0){
      cout << "here";
      fileread = false;
      done = true;
    }
  }
  
  int heaparray[102];
  if(fileread == true){ // if the user would like to read in from a file
  streampos size;
  char * memblock;
  char * pch;
  ifstream file ("example.txt", ios::in|ios::binary|ios::ate);
  if (file.is_open())
    {
      size = file.tellg();
      memblock = new char [size];
      file.seekg (0, ios::beg);
      file.read (memblock, size);
      file.close();

      //  cout << "the entire file content is in memory" << endl;
    }
  pch = strtok (memblock," ,.-");
  int i = 0;
  int temp = 0;
  for (int a = 1; a < 101; a++){
    heaparray[a] = 0;
  }
  
  while (pch != NULL)
    {
      temp = atoi(pch);
      //cout << pch << endl;
      heaparray[i] = temp;
      pch = strtok (NULL, " ,.-");
      cout << heaparray[i] << endl;
      i++;
    }
    //cout << firstname[numberofstudents] << endl;
    totalelements = i;
  delete[] memblock;
  }

  //int totalelements = 0;
  if(fileread == false){ //if the user wants to enter the numbers manually
     cout << "Enter the total number of elements (no more than 100) to sort:  "; 
     cin >> totalelements;
     
     cout << "input: "; 
     for (int a = 1; a < totalelements +1 ; a++){
       cout << a << "  ";
       cin >> heaparray[a];
     }
  }
  int finalarray[102]; // final array that will change throughut the program
  for (int a = 1; a < 101; a++){ // for loop to initoizalize all values to 0 in final array
    finalarray[a] = 0;
  }
  
  int lengthoflist = 0; //holds how many numbers have been entered into the final array
  for (int a = 1; a <= ((totalelements)); a++){
    lengthoflist = sortheap(&finalarray[0], heaparray[a], lengthoflist); //runs sorting method, and returns the amount of numbers sorted
  }
  //cout << "final: ";
  //for (int a = 1; a < 20; a++){
    //if (finalarray[a])
    //  cout << finalarray[a] << "   ";
      //else
      //break;
  //}
  cout << endl;

  printtreeshape(&finalarray[0], totalelements); //calls shape print
  
}

void printtree(int *heapa, int elements)
{
   for (int a = 1; a <= elements/2 + 1; a++){
    
     if (heapa[a]) {
      cout << "parent "<< a << ": "<< heapa[a] << " ";
      if (heapa[a*2])
	cout << "child left: " << heapa[a*2] << " ";
      if (heapa[a*2 + 1])
	cout << "child Right: " << heapa[a*2 +1] << endl;
     }
 
  }
 
  
}

void printtreeshape(int *heapa, int elements)
{
  int rounds = 0;
  int tempelements = elements;
  while (tempelements != 0){
    rounds++;
    tempelements = tempelements/2;
  }
  cout << rounds;
  int counter = 1;
  int space = pow(2, rounds);
   for (int a = 1; a <= rounds; a++){

     //if(a%2 == 0){
	//cout << "  ";
       //}
     
     
     for (int x = 0; x <= (rounds-a); x++){
       cout << "    ";
     }
     for (int b = 1; b <= pow(2, (a-1)); b++){
       cout << setw(4) << heapa[counter];
       //gap between elements
       for(int j = 1; j <= space; j++)
	    cout << " ";
       counter++;
     }
     cout << endl << endl;
     space = space/2;
  }
}


int sortheap(int *heapa, int i, int L){

  int movetemp = 0;
  
  for (int b = L; b >= 0; b--){
    heapa[b+1] = heapa[b];
  }
  cout << "Here: ";
  for (int a = 1; a < 102; a++){
    if(heapa[a])
     cout << heapa[a] << "  ";
    //else
    //break;
   }
  cout << endl;
   
    
  int indexofnew = 1;
  int value = i;
  int length = L;
  int temp = 0;
  bool inplace = false;
  heapa[1] = value;
  while(inplace == false){
    if((indexofnew <= (length/2)+1) && (heapa[indexofnew*2] < value) && (heapa[(indexofnew*2)+1] < value)){
      cout << value << "<-element is inplace" << " left child->  " << heapa[indexofnew*2] << "right child-> " << heapa[indexofnew*2 +1] <<  endl;
      inplace = true;
      //cout << "1";
       
    }
    else if((indexofnew <= (length/2)+1) && (heapa[indexofnew*2] > value) && (heapa[(indexofnew*2)+1] >= value)){
      bool foundspot = false;
      int counter = 0;
      if(heapa[indexofnew*2] > heapa[(indexofnew*2)+1]){
	temp = heapa[indexofnew*2];
	heapa[indexofnew*2] = value;
	heapa[indexofnew] = temp;
	indexofnew = (indexofnew*2); //

	cout << "switch with left(1)->" << endl;
      }
      else if(heapa[indexofnew*2] <= heapa[(indexofnew*2)+1]){
	temp = heapa[(indexofnew*2)+1];
	heapa[(indexofnew*2)+1] = value;
	heapa[indexofnew] = temp;
	indexofnew = (indexofnew*2)+1;
	cout << "switch with right(1)->" << endl;

      }

      
    }
    else if((indexofnew <= (length/2)+1) && (heapa[indexofnew*2] < value) && (heapa[(indexofnew*2)+1] > value)){
      temp = heapa[(indexofnew*2)+1];
      heapa[(indexofnew*2)+1] = value;
      heapa[indexofnew] = temp;
      indexofnew = (indexofnew*2)+1;
      cout << "switch with right(2)->" << endl;
    }
    else if((indexofnew <= (length/2)+1) && (heapa[indexofnew*2] > value) && (heapa[(indexofnew*2)+1] <= value)){
      temp = heapa[indexofnew*2];
      heapa[indexofnew*2] = value;
      heapa[indexofnew] = temp;
      indexofnew = indexofnew*2;
      cout << "switch with left(2)->" << endl;
    }    

    /*
    else if((indexofnew <= length/2) && (heapa[indexofnew*2] > value) && (heapa[(indexofnew*2)+1] > value)){
      bool foundspot = false;
      int counter = 0;
      
      while (foundspot == false){
	if(heapa[indexofnew*2 + counter] == 0){
	  heapa[indexofnew*2 + counter] = value;
	  foundspot = true;
	}
	else{
	  counter++;
	}
      }
      inplace = true;
      } */
    else {
      inplace = true;
    }
  }
  length++;
  return length;
}

