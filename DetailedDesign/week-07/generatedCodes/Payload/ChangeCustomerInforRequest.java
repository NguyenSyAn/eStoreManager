package Payload; 
public class ChangeCustomerInforRequest    { 
	 
	 
		private char name; 
	 
		private char email; 
	 
		private char mobileNo; 
	 
	 
		public final char getName() {
			return this.name;
		} 
		public final void setName(final char someName) {
			this.name = someName;
		} 
	 
		public final char getEmail() {
			return this.email;
		} 
		public final void setEmail(final char someEmail) {
			this.email = someEmail;
		} 
	 
		public final char getMobileNo() {
			return this.mobileNo;
		} 
		public final void setMobileNo(final char someMobileNo) {
			this.mobileNo = someMobileNo;
		} 
	 
} 