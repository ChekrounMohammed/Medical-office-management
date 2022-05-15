Application _ Medical practice management (version 1.0).


Directors: Chekroun Mohamed | Jabir Somaya | Taizoukt Anouar |

NB: The Compilation is under WINDOWS.

Build with: Dev C++

    Project description
    ===============
_____________________________________________________________________________________________
   IMPORTANT: The first access to this application is only valid by the "super user" who is whose

   the username is: secreaire.

   The password requested in the 1st interface is: azertyui
_____________________________________________________________________________________________

   This application allows you to handle the management of patients, employees, appointments, bills.
   From a medical office.

   To guarantee a permanent management to the user, this project contains functions which allow
   storing information in "*.txt" files.

   Patient management:
   =================

   This application allows employees to create, view, modify and delete
   patient files in a permanent way by storing the information of each patient
  in a file named "CIN_du _patient.txt".

   -Patient files will be stored in a directory named "patient".
     The latter also contains another archive directory where there is an "Archive_des_patient.txt" file.
     in which there is the archive of all patients' information (if a patient's file is modified
     it will be noted in the archive).

   -the invoice and medical certificate are two valid functions only for patients.

   Appointment management
   ====================

   The management of appointments is also made in a permanent way such that each reservation
   made by a patient who must already be registered, is added at the end of a file named
   "fichierDesRDV.txt" which is located in a directory named "repRDV".

   This application also allows the update of the "fichierDesRDV.txt" file.
   all appointments that are older than the current date will be deleted

   The "repRDV" directory contains another file named "dt_hr_dernierRDV.txt" which always contains
   the date and time of the next appointment.


   Employee management
   ==================

 - Employee management is only valid for "the super user" by:

   ** the username "secretary".
   ** the password "mohammed".

   This application allows the "super user" to create, display, modify and delete
    employee files also in a permanent way by storing the information of each employee
    in a "CIN_du _employees.txt" file.

   -The employee files will be stored in a directory named "employee".

   - only employees who have the right to use this application such as the first window of this
    last is a login interface which asks for a user name (for each employee the user name is his CIN),
    
    and a password which is "azertyui".

   employees are able to send a leave request and specify its duration.
