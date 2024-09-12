#ifndef TINYFILEDIALOGS_H
#define TINYFILEDIALOGS_H

#ifdef __cplusplus
extern "C" {
#endif

 // Function to open a file dialog and return the selected file path
 const char* tinyfd_openFileDialog(
     const char* aTitle,
     const char* aDefaultPathAndFile,
     int aNumOfFilterPatterns,
     const char** aFilterPatterns,
     const char* aSingleFilterDescription,
     int aAllowMultipleSelects
 );

#ifdef __cplusplus
}
#endif

#endif // TINYFILEDIALOGS_H
