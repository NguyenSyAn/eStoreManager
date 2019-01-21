1. Use case code: UC001

2. Use case name: Log in

3. Actor: User (Customer, Bank Officer)

4. Pre-condition: None

5. Main flow of events (Success):

  | No   | Actor  | Action                                          |
  | ---- | ------ | ----------------------------------------------- |
  | 1    | User   | Select Log in function                          |
  | 2    | System | Display log in interface                        |
  | 3    | User   | Input user name and passwords                   |
  | 4    | User   | Request Log in                                  |
  | 5    | System | Check whether user had input the required field |
  | 6    | System | Validate the user name and password             |
  | 7    | System | Log user into the system                        |
  | 8    | System | Display the Main Form and the use case end      |

  

6. Alternative flow of events:

  | No   | Actor  | Action                                                       |
  | ---- | ------ | ------------------------------------------------------------ |
  | 6a.  | System | Output error: need to put into the missing required field if had not done so |
  | 7a.  | System | Output error: If the user name and password is invalid, require user enter user name and password again |

   

7. Post-condition: None

   