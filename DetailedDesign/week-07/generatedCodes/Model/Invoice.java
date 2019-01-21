package Model; 
public class Invoice    { 
	 
	 
		private int id; 
	 
		private int purpose; 
	 
		private int description; 
	 
		private int amount; 
	 
	 
		public final int getId() {
			return this.id;
		} 
		public final void setId(final int someId) {
			this.id = someId;
		} 
	 
		public final int getPurpose() {
			return this.purpose;
		} 
		public final void setPurpose(final int somePurpose) {
			this.purpose = somePurpose;
		} 
	 
		public final int getDescription() {
			return this.description;
		} 
		public final void setDescription(final int someDescription) {
			this.description = someDescription;
		} 
	 
		public final int getAmount() {
			return this.amount;
		} 
		public final void setAmount(final int someAmount) {
			this.amount = someAmount;
		} 
	 
} 