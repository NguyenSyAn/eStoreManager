1. Use case code: UC002

2. Use case name: Change password

3. Actor: User (Customer, Bank Officer)

4. Pre-condition: User logged in system

5. Main flow of events (Success):

| No   | Actor  | Action                                                       |
| ---- | ------ | ------------------------------------------------------------ |
| 1    | User   | Select change password function                              |
| 2    | System | Display change password interface, require confirm old password and new password |
| 3    | User   | Enter old password and new password                          |
| 4    | System | Check whether user had input the required field              |
| 5    | System | Check the new password is secure enough or not               |
| 6    | System | Check the old password is right or not                       |
| 7    | System | Display change password successfully, save new password      |


6. Alternative flow of events:

| No   | Actor  | Action                                                       |
| ---- | ------ | ------------------------------------------------------------ |
| 5a.  | System | Output error: need to put into the missing required field if had not done so |
| 6a.  | System | Output error: the new password is not secure enough, back to step confirm password |
| 7a.  | System | Output error: the old password is not right, back to step confirm password |


7. Post-condition: None

   