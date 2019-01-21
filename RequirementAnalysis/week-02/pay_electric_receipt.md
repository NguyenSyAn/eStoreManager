1. Use case code: UC004

2. Use case name: Pay electric receipt
   
3. Actor: Customer, EVN Software

4. Pre-condition: Customer has logged in

5. Main flow of events (Success):

  | No   | Actor  | Action                                          |
  | ---- | ------ | ----------------------------------------------- |
  | 1    | Customer   | Request electric receipt payment and enter the receipt id    |
  | 2    | System | Connect with EVN to get receipt payment info        |
  | 3    | EVN Software | Return payment info with the provided receipt id or an error message |
  | 4    | System | Check the customer balance if there is enough money to pay for the receipt |
  | 5    | System | Transfer money to EVN account then inform the EVN software |
  | 6    | EVN Software | Confirm the payment |
  | 7    | System | Inform customer that payment was successful |

6. Alternative flow of events:

   | No   | Actor  | Action                                                       |
   | ---- | ------ | ------------------------------------------------------------ |
   | 2a.  | System | Output error if customer do not enter the receipt id |
   | 4a.  | System | Output error if receipt id is not valid |
   | 5a.  | System | Output error if there is not enough money in the Customer account|
   | 7a.  | System | Output error if there is an error on the transaction |

7. Post-condition: None

   