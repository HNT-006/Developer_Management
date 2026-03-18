#ifndef FILEHELPER_H
#define FILEHELPER_H

#include "Developer.h"
#include "Project.h"
#include "Common.h"
#include "Operations.h"
//===================== DEVELOPER FILE HANDLING =====================

// Save all developers to file
void saveDevToFile();

// Load developers from file
void loadDevelopersFromFile();

//===================== PROJECT FILE HANDLING =======================

// Save all projects to file
void saveProjectsToFile();

// Load projects from file
void loadProjectsFromFile();

#endif