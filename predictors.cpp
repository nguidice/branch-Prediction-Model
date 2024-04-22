// NEED TO DO #1 fix formating (DONE) #2 print to output file (DONE) #3 get input file from command line (DONE) # 4 rest of project (ghshare needs to be correctd, tournament and BTB needs to be implemented) // 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//Variables
string file;
string outputFile;
unsigned long long addr;
string behavior, line;
unsigned long long target = 0;
unsigned long long correct = 0;
unsigned long long total = 0;
//std::ofstream fout("output.txt");


void alwaysTaken (string file, std::ofstream& fout){

// Open file for reading
  ifstream infile(file);

  target = 0; 
  correct = 0;
  total = 0; 
  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;
    
    if (behavior == "T"){
        correct++;
    }

  }

  fout << correct << "," << total << ";" << endl;

}

void alwaysNotTaken (string file, std::ofstream& fout){

// Open file for reading
  ifstream infile(file);

  target = 0; 
  correct = 0;
  total = 0; 
  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;
    
    if (behavior == "NT"){
        correct++;
    }

  }
    fout << correct << "," << total << ";" << endl;
}

void singleBimodal(string file, std::ofstream& fout){
  // Open file for reading
  ifstream infile(file);

  target = 0; 
  correct = 0;
  total = 0; 
  int indx = 0;

  //Intilize Vectors
      vector<string> Tbl16(16,"T");
      vector<string> Tbl32(32,"T");
      vector<string> Tbl128(128,"T");
      vector<string> Tbl256(256,"T");
      vector<string> Tbl512(512,"T");
      vector<string> Tbl1024(1024,"T");
      vector<string> Tbl2048(2048,"T");


  // 16 Bit Table ///////////////////////////////////////

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 15;
    
    if (behavior == Tbl16.at(indx)){
        correct++;
    }
    else {
      Tbl16.at(indx) = behavior;
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
//////////////////////////////////////////////////////////


  // 32 Bit Table ///////////////////////////////////////

  //Reintialize variables
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 31;
    
    if (behavior == Tbl32.at(indx)){
        correct++;
    }
    else {
      Tbl32.at(indx) = behavior;
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////


  // 128 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 127;
    
    if (behavior == Tbl128.at(indx)){
        correct++;
    }
    else {
      Tbl128.at(indx) = behavior;
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  // 256 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 255;
    
    if (behavior == Tbl256.at(indx)){
        correct++;
    }
    else {
      Tbl256.at(indx) = behavior;
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  // 512 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 511;
    
    if (behavior == Tbl512.at(indx)){
        correct++;
    }
    else {
      Tbl512.at(indx) = behavior;
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  // 1024 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 1023;
    
    if (behavior == Tbl1024.at(indx)){
        correct++;
    }
    else {
      Tbl1024.at(indx) = behavior;
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  // 2048 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 2047;
    
    if (behavior == Tbl2048.at(indx)){
        correct++;
    }
    else {
      Tbl2048.at(indx) = behavior;
    }

  }
    fout << correct <<"," << total << ";" << endl;
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////
}

void doubleBimodal(string file, std::ofstream& fout){
  // Open file for reading
  ifstream infile(file);

  target = 0; 
  correct = 0;
  total = 0; 
  int indx = 0;

  //Intilize Vectors
      vector<string> Tbl16(16,"TT");
      vector<string> Tbl32(32,"TT");
      vector<string> Tbl128(128,"TT");
      vector<string> Tbl256(256,"TT");
      vector<string> Tbl512(512,"TT");
      vector<string> Tbl1024(1024,"TT");
      vector<string> Tbl2048(2048,"TT");


  // 16 Bit Table ///////////////////////////////////////

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 15;
    
    //Check against prediction table and update as needed
    if (behavior == "T" && (Tbl16.at(indx) == "WT" || Tbl16.at(indx) == "TT")){
        correct++;
        if(Tbl16.at(indx) == "WT"){
          Tbl16.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl16.at(indx) == "WNT" || Tbl16.at(indx) == "SNT")){
          correct++;
          if(Tbl16.at(indx) == "WNT"){
            Tbl16.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl16.at(indx) == "TT" || Tbl16.at(indx) == "WT")){
      if (Tbl16.at(indx) == "WT"){
        Tbl16.at(indx) = "WNT";
      }
      if(Tbl16.at(indx) == "TT"){
        Tbl16.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl16.at(indx) == "SNT" || Tbl16.at(indx) == "WNT")){
      if (Tbl16.at(indx) == "WNT"){
        Tbl16.at(indx) = "WT";
      }
      if(Tbl16.at(indx) == "SNT"){
        Tbl16.at(indx) = "WNT";
      }
    }


  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
//////////////////////////////////////////////////////////


  // 32 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 31;
    
    //Check against prediction table and update as needed
    if (behavior == "T" && (Tbl32.at(indx) == "WT" || Tbl32.at(indx) == "TT")){
        correct++;
        if(Tbl32.at(indx) == "WT"){
          Tbl32.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl32.at(indx) == "WNT" || Tbl32.at(indx) == "SNT")){
          correct++;
          if(Tbl32.at(indx) == "WNT"){
            Tbl32.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl32.at(indx) == "TT" || Tbl32.at(indx) == "WT")){
      if (Tbl32.at(indx) == "WT"){
        Tbl32.at(indx) = "WNT";
      }
      if(Tbl32.at(indx) == "TT"){
        Tbl32.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl32.at(indx) == "SNT" || Tbl32.at(indx) == "WNT")){
      if (Tbl32.at(indx) == "WNT"){
        Tbl32.at(indx) = "WT";
      }
      if(Tbl32.at(indx) == "SNT"){
        Tbl32.at(indx) = "WNT";
      }
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////


  // 128 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 127;
    
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl128.at(indx) == "WT") || Tbl128.at(indx) == "TT")){
        correct++;
        if(Tbl128.at(indx) == "WT"){
          Tbl128.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl128.at(indx) == "WNT" || Tbl128.at(indx) == "SNT")){
          correct++;
          if(Tbl128.at(indx) == "WNT"){
            Tbl128.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl128.at(indx) == "TT" || Tbl128.at(indx) == "WT")){
      if (Tbl128.at(indx) == "WT"){
        Tbl128.at(indx) = "WNT";
      }
      if(Tbl128.at(indx) == "TT"){
        Tbl128.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl128.at(indx) == "SNT" || Tbl128.at(indx) == "WNT")){
      if (Tbl128.at(indx) == "WNT"){
        Tbl128.at(indx) = "WT";
      }
      if(Tbl128.at(indx) == "SNT"){
        Tbl128.at(indx) = "WNT";
      }
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  // 256 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 255;
    
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl256.at(indx) == "WT") || Tbl256.at(indx) == "TT")){
        correct++;
        if(Tbl256.at(indx) == "WT"){
          Tbl256.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl256.at(indx) == "WNT" || Tbl256.at(indx) == "SNT")){
          correct++;
          if(Tbl256.at(indx) == "WNT"){
            Tbl256.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl256.at(indx) == "TT" || Tbl256.at(indx) == "WT")){
      if (Tbl256.at(indx) == "WT"){
        Tbl256.at(indx) = "WNT";
      }
      if(Tbl256.at(indx) == "TT"){
        Tbl256.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl256.at(indx) == "SNT" || Tbl256.at(indx) == "WNT")){
      if (Tbl256.at(indx) == "WNT"){
        Tbl256.at(indx) = "WT";
      }
      if(Tbl256.at(indx) == "SNT"){
        Tbl256.at(indx) = "WNT";
      }
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  // 512 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 511;
    
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl512.at(indx) == "WT") || Tbl512.at(indx) == "TT")){
        correct++;
        if(Tbl512.at(indx) == "WT"){
          Tbl512.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl512.at(indx) == "WNT" || Tbl512.at(indx) == "SNT")){
          correct++;
          if(Tbl512.at(indx) == "WNT"){
            Tbl512.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl512.at(indx) == "TT" || Tbl512.at(indx) == "WT")){
      if (Tbl512.at(indx) == "WT"){
        Tbl512.at(indx) = "WNT";
      }
      if(Tbl512.at(indx) == "TT"){
        Tbl512.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl512.at(indx) == "SNT" || Tbl512.at(indx) == "WNT")){
      if (Tbl512.at(indx) == "WNT"){
        Tbl512.at(indx) = "WT";
      }
      if(Tbl512.at(indx) == "SNT"){
        Tbl512.at(indx) = "WNT";
      }
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  // 1024 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 1023;
    
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl1024.at(indx) == "WT") || Tbl1024.at(indx) == "TT")){
        correct++;
        if(Tbl1024.at(indx) == "WT"){
          Tbl1024.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl1024.at(indx) == "WNT" || Tbl1024.at(indx) == "SNT")){
          correct++;
          if(Tbl1024.at(indx) == "WNT"){
            Tbl1024.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl1024.at(indx) == "TT" || Tbl1024.at(indx) == "WT")){
      if (Tbl1024.at(indx) == "WT"){
        Tbl1024.at(indx) = "WNT";
      }
      if(Tbl1024.at(indx) == "TT"){
        Tbl1024.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl1024.at(indx) == "SNT" || Tbl1024.at(indx) == "WNT")){
      if (Tbl1024.at(indx) == "WNT"){
        Tbl1024.at(indx) = "WT";
      }
      if(Tbl1024.at(indx) == "SNT"){
        Tbl1024.at(indx) = "WNT";
      }
    }

  }
    fout << correct <<"," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  // 2048 Bit Table ///////////////////////////////////////

  //reintilize varibles
  target = 0; 
  correct = 0;
  total = 0; 
  indx = 0;

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  //& addr with length of table for 16 bit table
  indx = addr & 2047;
    
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }

  }
    fout << correct <<"," << total << ";" << endl;
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////
}

void gShare(string file, std::ofstream& fout){
  // Open file for reading
  ifstream infile(file);

  int finGHR = 0;
  target = 0; 
  correct = 0;
  total = 0; 
  int indx = 0;

  //3 Bit GHR////////////////////////////////

  vector<int> GHR3 (3,0);
  vector<string> Tbl2048(2048,"TT");

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  indx = addr & 2047;

    //GHR vector to integer
    finGHR = (GHR3[0] << 2) | (GHR3[1] << 1) | GHR3[2];

    //xor GHR
    indx = (indx ^ finGHR);

    //if correct add
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }
    
      //Shift GHR
      //Parse GHR
      for(int i=1; i<GHR3.size(); i++){
          GHR3.at(i-1) = GHR3.at(i);
        }
      //If GHR = T
      if(behavior == "T"){
        GHR3.at(GHR3.size()-1) = 1;
      }
      else{ 
        GHR3.at(GHR3.size()-1) = 0;
      }
  }
    fout << correct << "," << total << "; ";
  infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  //4 Bit GHR////////////////////////////////

  correct = 0;
  total = 0;
  vector<int> GHR4 (4,0);

  for (int i = 0; i < Tbl2048.size(); i++){
    Tbl2048.at(i) = "TT";
  }

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  indx = addr & 2047;

    //GHR vector to integer
    finGHR = (GHR4[0] << 3) | (GHR4[1] << 2) | GHR4[2] << 1 | GHR4[3];

    //xor GHR
    indx = (indx ^ finGHR);

    //if correct add
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }
    
      //Shift GHR
      //Parse GHR
      for(int i=1; i<GHR4.size(); i++){
          GHR4.at(i-1) = GHR4.at(i);
        }
      //If GHR = T
      if(behavior == "T"){
        GHR4.at(GHR4.size()-1) = 1;
      }
      else{ 
        GHR4.at(GHR4.size()-1) = 0;
      }
  }
    fout << correct << "," << total << "; ";
    infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

   //5 Bit GHR////////////////////////////////

  correct = 0;
  total = 0;
  vector<int> GHR5 (5,0);

  for (int i = 0; i < Tbl2048.size(); i++){
    Tbl2048.at(i) = "TT";
  }

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  indx = addr & 2047;

    //GHR vector to integer
    finGHR = (GHR5[0] << 4) | (GHR5[1] << 3) | GHR5[2] << 2 | GHR5[3] << 1 | GHR5[4];

    //xor GHR
    indx = (indx ^ finGHR);

    //if correct add
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }
    
      //Shift GHR
      //Parse GHR
      for(int i=1; i<GHR5.size(); i++){
          GHR5.at(i-1) = GHR5.at(i);
        }
      //If GHR = T
      if(behavior == "T"){
        GHR5.at(GHR5.size()-1) = 1;
      }
      else{ 
        GHR5.at(GHR5.size()-1) = 0;
      }
  }
    fout << correct << "," << total << "; ";
    infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  //6 Bit GHR////////////////////////////////

  correct = 0;
  total = 0;
  vector<int> GHR6 (6,0);

  for (int i = 0; i < Tbl2048.size(); i++){
    Tbl2048.at(i) = "TT";
  }

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  indx = addr & 2047;

    //GHR vector to integer
    finGHR = (GHR6[0] << 5) | (GHR6[1] << 4) | GHR6[2] << 3 | GHR6[3] << 2 | GHR6[4] << 1| GHR6[5];

    //xor GHR
    indx = (indx ^ finGHR);

    //if correct add
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }
    
      //Shift GHR
      //Parse GHR
      for(int i=1; i<GHR6.size(); i++){
          GHR6.at(i-1) = GHR6.at(i);
        }
      //If GHR = T
      if(behavior == "T"){
        GHR6.at(GHR6.size()-1) = 1;
      }
      else{ 
        GHR6.at(GHR6.size()-1) = 0;
      }
  }
    fout << correct << "," << total << "; ";
    infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  //7 Bit GHR////////////////////////////////

  correct = 0;
  total = 0;
  vector<int> GHR7 (7,0);

  for (int i = 0; i < Tbl2048.size(); i++){
    Tbl2048.at(i) = "TT";
  }

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  indx = addr & 2047;

    //GHR vector to integer
    finGHR = (GHR7[0] << 6) | (GHR7[1] << 5) | GHR7[2] << 4 | GHR7[3] << 3 | GHR7[4] << 2| GHR7[5] << 1 | GHR7[6];

    //xor GHR
    indx = (indx ^ finGHR);

    //if correct add
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }
    
      //Shift GHR
      //Parse GHR
      for(int i=1; i<GHR7.size(); i++){
          GHR7.at(i-1) = GHR7.at(i);
        }
      //If GHR = T
      if(behavior == "T"){
        GHR7.at(GHR7.size()-1) = 1;
      }
      else{ 
        GHR7.at(GHR7.size()-1) = 0;
      }
  }
    fout << correct << "," << total << "; ";
    infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  //8 Bit GHR////////////////////////////////

  correct = 0;
  total = 0;
  vector<int> GHR8 (8,0);

  for (int i = 0; i < Tbl2048.size(); i++){
    Tbl2048.at(i) = "TT";
  }

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  indx = addr & 2047;

    //GHR vector to integer
    finGHR = (GHR8[0] << 7) | (GHR8[1] << 6) | GHR8[2] << 5 | GHR8[3] << 4 | GHR8[4] << 3| GHR8[5] << 2 | GHR8[6] << 1 | GHR8[7];

    //xor GHR
    indx = (indx ^ finGHR);

    //if correct add
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }
    
      //Shift GHR
      //Parse GHR
      for(int i=1; i<GHR8.size(); i++){
          GHR8.at(i-1) = GHR8.at(i);
        }
      //If GHR = T
      if(behavior == "T"){
        GHR8.at(GHR8.size()-1) = 1;
      }
      else{ 
        GHR8.at(GHR8.size()-1) = 0;
      }
  }
    fout << correct << "," << total << "; ";
    infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  //9 Bit GHR////////////////////////////////

  correct = 0;
  total = 0;
  vector<int> GHR9 (9,0);

  for (int i = 0; i < Tbl2048.size(); i++){
    Tbl2048.at(i) = "TT";
  }

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  indx = addr & 2047;

    //GHR vector to integer
    finGHR = (GHR9[0] << 8) | (GHR9[1] << 7) | GHR9[2] << 6 | GHR9[3] << 5 | GHR9[4] << 4| GHR9[5] << 3 | GHR9[6] << 2 | GHR9[7] << 1 | GHR9[8];

    //xor GHR
    indx = (indx ^ finGHR);

    //if correct add
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }
    
      //Shift GHR
      //Parse GHR
      for(int i=1; i<GHR9.size(); i++){
          GHR9.at(i-1) = GHR9.at(i);
        }
      //If GHR = T
      if(behavior == "T"){
        GHR9.at(GHR9.size()-1) = 1;
      }
      else{ 
        GHR9.at(GHR9.size()-1) = 0;
      }
  }
    fout << correct << "," << total << "; ";
    infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////
  
  //10 Bit GHR////////////////////////////////

  correct = 0;
  total = 0;
  vector<int> GHR10 (10,0);

  for (int i = 0; i < Tbl2048.size(); i++){
    Tbl2048.at(i) = "TT";
  }

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  indx = addr & 2047;

    //GHR vector to integer
    finGHR = (GHR10[0] << 9) | (GHR10[1] << 8) | GHR10[2] << 7 | GHR10[3] << 6 | GHR10[4] << 5| GHR10[5] << 4 | GHR10[6] << 3 | GHR10[7] << 2 | GHR10[8] << 1 | GHR10[9];

    //xor GHR
    indx = (indx ^ finGHR);

    //if correct add
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }
    
      //Shift GHR
      //Parse GHR
      for(int i=1; i<GHR10.size(); i++){
          GHR10.at(i-1) = GHR10.at(i);
        }
      //If GHR = T
      if(behavior == "T"){
        GHR10.at(GHR10.size()-1) = 1;
      }
      else{ 
        GHR10.at(GHR10.size()-1) = 0;
      }
  }
    fout << correct << "," << total << "; ";
    infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////

  //11 Bit GHR////////////////////////////////

  correct = 0;
  total = 0;
  vector<int> GHR11 (11,0);

  for (int i = 0; i < Tbl2048.size(); i++){
    Tbl2048.at(i) = "TT";
  }

  // The following loop will read a line at a time
  while(getline(infile, line)) {
  total++;
  // Now we have to parse the line into it's two pieces
  stringstream s(line);
  s >> std::hex >> addr >> behavior >> std::hex >> target;

  indx = addr & 2047;

    //GHR vector to integer
    finGHR = (GHR11[0] << 10) | (GHR11[1] << 9) | GHR11[2] << 8 | GHR11[3] << 7 | GHR11[4] << 6| GHR11[5] << 5 | GHR11[6] << 4 | GHR11[7] << 3 | GHR11[8] << 2 | GHR11[9] << 1 | GHR11[10];

    //xor GHR
    indx = (indx ^ finGHR);

    //if correct add
    //Check against prediction table and update as needed
    if (behavior == "T" && ((Tbl2048.at(indx) == "WT") || Tbl2048.at(indx) == "TT")){
        correct++;
        if(Tbl2048.at(indx) == "WT"){
          Tbl2048.at(indx) = "TT";
        }
    }
        else if (behavior == "NT" && (Tbl2048.at(indx) == "WNT" || Tbl2048.at(indx) == "SNT")){
          correct++;
          if(Tbl2048.at(indx) == "WNT"){
            Tbl2048.at(indx) = "SNT";
          }
        }
    
    //If wrong
    else if (behavior == "NT" && (Tbl2048.at(indx) == "TT" || Tbl2048.at(indx) == "WT")){
      if (Tbl2048.at(indx) == "WT"){
        Tbl2048.at(indx) = "WNT";
      }
      if(Tbl2048.at(indx) == "TT"){
        Tbl2048.at(indx) = "WT";
      }
    }

    else if (behavior == "T" && (Tbl2048.at(indx) == "SNT" || Tbl2048.at(indx) == "WNT")){
      if (Tbl2048.at(indx) == "WNT"){
        Tbl2048.at(indx) = "WT";
      }
      if(Tbl2048.at(indx) == "SNT"){
        Tbl2048.at(indx) = "WNT";
      }
    }
    
      //Shift GHR
      //Parse GHR
      for(int i=1; i<GHR11.size(); i++){
          GHR11.at(i-1) = GHR11.at(i);
        }
      //If GHR = T
      if(behavior == "T"){
        GHR11.at(GHR11.size()-1) = 1;
      }
      else{ 
        GHR11.at(GHR11.size()-1) = 0;
      }
  }
    fout << correct << "," << total << ";" << endl;
    infile.close();
  infile.open(file);
  //////////////////////////////////////////////////////////
}


void tournament (string file, std::ofstream& fout){
  // Open file for reading
  ifstream infile(file);

  int finGHR = 0;
  target = 0; 
  correct = 0;
  total = 0; 
  int indx = 0;
  int gindx = 0;
  int biT = 0;
  int biNT = 0;
  int gT = 0;
  int gNT = 0;
  int gCorrect = 0;
  int biCorrect = 0;

  string gPredict, biPredict,samePredict;
  vector<int> GHR11(11,0);
  vector<string> bi2048(2048,"ST");
  vector<string> g2048(2048,"ST");
  vector<string> select2048(2048,"SG");
    
    while(getline(infile, line)) {
      total ++;
      stringstream s(line);
      s >> std::hex >> addr >> behavior >> std::hex >> target;
     
      indx = addr & 2047;
      gindx = indx;
      // convert GHR bits to an integer
      finGHR = (GHR11[0] << 10) | (GHR11[1] << 9) | (GHR11[2] << 8) | (GHR11[3] << 7) | (GHR11[4] << 6) | (GHR11[5] << 5) | (GHR11[6] << 4) | (GHR11[7] << 3) | (GHR11[8]<<2) | (GHR11[9] << 1) | GHR11[10];
      //xor against ghr
      gindx = (gindx ^ finGHR);
      // now that we have both indices
      //we will store both of their predictions
      gPredict = g2048.at(gindx);
      biPredict = bi2048.at(indx);
      samePredict = select2048.at(indx);
      
  //IF GShare
  //IF PREDICTION IS CORRECT
  if( (behavior == "T" && (gPredict == "WT"|| gPredict == "ST")) || (behavior == "NT" && (gPredict == "WNT" || gPredict == "SNT")) ){
    //mark gShareCorrect 
    gCorrect = 1;
    //IF BEHAVIOR = TAKEN
    if(behavior == "T" && (gPredict == "WT"|| gPredict == "ST")){
      //if pred = WT, move next pred to ST
      if(gPredict == "WT"){
        g2048.at(gindx) = "ST";
        }
    }
    //IF BEHAVIOR = NOT TAKEN
    else if(behavior == "NT" && (gPredict == "WNT" || gPredict == "SNT")){
      //if pred = WNT, move next pred to SNT
      if(gPredict == "WNT"){
        g2048.at(gindx) = "SNT";
        }
    }
  }
  //IF PREDICTION IS INCORRECT
  else{
    //mark gShareCorrect to 0
    gCorrect = 0;
    // AND BEHAVIOR = NOT TAKEN
    if(behavior == "NT"){
      //if we were at WT, we can shift to WNT, else, we were at ST and need to shift to WT
      if(gPredict == "WT"){
        g2048.at(gindx) = "WNT";
        }
      else{
        g2048.at(gindx) = "WT";
        }
    }
    //AND BEHAVIOR = TAKEN
    else if(behavior == "T"){
      // if behavior was WNT change to WT otherwise we must have been at strongly not taken, and must shift down to weakly not taken
      if(gPredict == "WNT"){ 
        g2048.at(gindx) = "WT"; 
        }
      else{ 
        g2048.at(gindx) = "WNT"; 
        }
    }
  }

      //BIMODAL
  //IF PREDICTION IS CORRECT
  if( (behavior == "T" && (biPredict == "WT"|| biPredict == "ST") ) || (behavior == "NT" && (biPredict == "WNT" || biPredict == "SNT") ) ){
    //mark bimodCorrect 
    biCorrect = 1;
    //IF BEHAVIOR = TAKEN
      if(behavior == "T" && (biPredict == "WT"|| biPredict == "ST")){
        //if pred = WT, move next pred to ST
        if(biPredict == "WT"){
          bi2048.at(indx) = "ST";
          }
      }
    //IF BEHAVIOR = NOT TAKEN
      else if(behavior == "NT" && (biPredict == "WNT" || biPredict == "SNT")){
        //if pred = WNT, move next pred to SNT
        if(biPredict == "WNT"){
          bi2048.at(indx) = "SNT";
          }
      }
  }
  //IF PREDICTION IS INCORRECT
  else{
    //mark bimodCorrect to 0
    biCorrect = 0;
    // AND BEHAVIOR = NOT TAKEN
      if(behavior == "NT"){
        //if we were at WT, we can shift to WNT, else, we were at ST and need to shift to WT
        if(biPredict == "WT"){
          bi2048.at(indx) = "WNT";
          }
        else{
          bi2048.at(indx) = "WT";
          }
      }
    //AND BEHAVIOR = TAKEN
      else if(behavior == "T"){
        // if behavior was WNT change to WT otherwise we must have been at strongly not taken, and must shift down to weakly not taken
        if(biPredict == "WNT"){ 
          bi2048.at(indx) = "WT"; 
          }
        else{ 
          bi2048.at(indx) = "WNT"; 
          }
      }
  }
//SHIFTING GSHARE AND BIMODAL
  //NOT TAKEN
  if(behavior == "NT"){
        //need to check if our bimodal index needs to be shifted towards NT                
        if(biPredict == "ST"){bi2048.at(indx) = "WT";}
        else if(biPredict == "WT"){bi2048.at(indx) = "WNT";}
        else if(biPredict == "WNT"){bi2048.at(indx) = "SNT";}
        //we also need to check if our gShare index needs to be shifted towards NT                
        if(gPredict == "ST"){
          g2048.at(gindx) = "WT";
          }
        else if(gPredict == "WT"){
          g2048.at(gindx) = "WNT";
          }
        else if(gPredict == "WNT"){
          g2048.at(gindx) = "SNT";
          }
  }
  // TAKEN
  if(behavior == "T"){
        //to check if our bimodal index needs to be shifted                   
        if(biPredict == "SNT"){
          bi2048.at(indx) = "WNT";
          }
        else if(biPredict == "WNT"){
          bi2048.at(indx) = "WT";
          }

        else if(biPredict == "WT"){
          bi2048.at(indx) = "ST";
          }
      
        //to check if our gShare index needs to be shifted                   
        if(gPredict == "SNT"){
          g2048.at(gindx) = "WNT";
          }
        else if(gPredict == "WNT"){
          g2048.at(gindx) = "WT";
          }
        else if(gPredict == "WT"){
          g2048.at(gindx) = "ST";
          }       
  }
//SELECTOR
    //if our selector was on gShare and gshare was correct, correct ++ and vice versa for bimod
    if( (select2048.at(indx) == "SG" || select2048.at(indx) == "WG") && gCorrect == 1){
      correct++;
      }
    else if( (select2048.at(indx) == "SB" || select2048.at(indx) == "WB") && biCorrect == 1){
      correct++;
      }
    //if outcomes were the same for both bimodal and gshare, reset selector to initial prediction
    if(biCorrect == gCorrect) { 
      select2048.at(indx) = samePredict; 
      }
    //else, if bimod was correct and g was incorrect
    else if(biCorrect == 1 && gCorrect == 0){
      //we move towards bimodal
      if(select2048.at(indx) == "SG"){ 
        select2048.at(indx) = "WG";
        }
      else if(select2048.at(indx) == "WG"){
        select2048.at(indx) = "WB";
        }
      else if(select2048.at(indx) == "WB"){
        select2048.at(indx) = "SB";
        }  
    }
    else if(biCorrect == 0 && gCorrect == 1){
      //we move towards gShare
      if(select2048.at(indx) == "SB"){ 
        select2048.at(indx) = "WB";
      }
      else if(select2048.at(indx) == "WB"){
        select2048.at(indx) = "WG";
        }
      else if(select2048.at(indx) == "WG"){
        select2048.at(indx) = "SG";
        }  
    }

    //now we want to shift ghr to the left
      //go through the ghr vector +1 because were tossing the oldest bit
      for(int i = 1; i < GHR11.size(); i++){
          GHR11.at(i-1) = GHR11.at(i);
        }
      //now if ghr behavior was T, set 
      if(behavior == "T"){
        GHR11.at(GHR11.size()-1) = 1;
      }
      else{ 
        GHR11.at(GHR11.size()-1) = 0;
      }
  }
  
    fout << correct <<"," << total << ";" << endl;
}



int main(int argc, char *argv[]) {

//Argument Check
if (argc < 3 || argc > 3){
  cout << "Incorrect Formatting" << endl;
  cout << "Plase Enter The Format ./Predictors inputFileName.txt outputFileName.txt" << endl;
  return 1;
}

file = argv[1];
outputFile = argv[2];

std::ofstream fout(outputFile);

alwaysTaken(file,fout);
alwaysNotTaken(file,fout);
singleBimodal(file,fout);
doubleBimodal(file,fout);
gShare(file,fout);
tournament(file,fout);

fout.close();

  return 0;
}
