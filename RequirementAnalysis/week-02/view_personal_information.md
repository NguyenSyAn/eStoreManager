1. Use case code: UC003

2. Use case name: View Personal Information

3. Actor: User (Customer, Bank Officer)

4. Pre-condition: None

5. Main flow of events (Success):

  | No   | Actor  | Action                                          |
  | ---- | ------ | ----------------------------------------------- |
  | 1    | User/BankOfficer   | Request personal information        |
  | 2    | System | Check if the user/bank officer has logged in        |
  | 3    | System | Display the personal information                   |
  

6. Alternative flow of events:

   | No   | Actor  | Action                                                       |
   | ---- | ------ | ------------------------------------------------------------ |
   | 2a.  | System | Output error and redirect to login page if user / bank officer hasn't logged in |

7. Post-condition: None

   