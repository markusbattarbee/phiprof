/*
This file is part of the phiprof library

Copyright 2012, 2013, 2014, 2015 Finnish Meteorological Institute
Copyright 2015, 2016 CSC - IT Center for Science 

Phiprof is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <string>
#include "phiprof.hpp"
#include <stdio.h>
#include <stdarg.h>

using namespace std;

extern "C" int phiprof_initializeTimer(char *label,int nGroups, ... ){
  va_list listPointer;
  vector<string> groupStrings;
  va_start( listPointer, nGroups );

  for (int i=0;i<nGroups;i++)  {
      char *group = va_arg( listPointer, char* );
      groupStrings.push_back(string(group));
  }
  va_end( listPointer );

  return phiprof::initializeTimer(string(label),groupStrings);

}

extern "C" int phiprof_getId(char *label){
  return phiprof::getId(string(label));
}


//start timer, with label
extern "C" int phiprof_start(char *label){
  return (int)phiprof::start(string(label));
  
}

//stop timer, with label
extern "C" int phiprof_stop(char *label){
  return (int)phiprof::stop(string(label));
}

//stop timer, with label and workunits
extern "C" int phiprof_stopUnits(char *name,double units,char *unitName){
  return (int)phiprof::stop(string(name),units,string(unitName));
}

//start timer, with label
extern "C" int phiprof_startId(int id){
  return (int)phiprof::start(id); 
}

//stop timer, with label
extern "C" int phiprof_stopId(int id){
  return (int)phiprof::stop(id);
}

//stop timer, with label and workunits
extern "C" int phiprof_stopIdUnits(int id,double units,char *unitName){
  return (int)phiprof::stop(id,units,string(unitName));
}


extern "C" int phiprof_print(MPI_Comm comm, char *fileNamePrefix){
  return (int)phiprof::print(comm,string(fileNamePrefix));
}

extern "C"  void phiprof_phiprofAssert(int condition, char *errorMessage, char *fileName, int line ) {
   phiprof::phiprofAssert(condition != 0,string(errorMessage), string(fileName), line);
}
