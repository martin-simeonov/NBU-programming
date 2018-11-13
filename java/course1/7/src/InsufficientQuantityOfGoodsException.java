
public class InsufficientQuantityOfGoodsException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = -8592443700776593626L;
	
	private Goods goods;
	
	public InsufficientQuantityOfGoodsException(Goods goods) {
		this.goods = goods;
	}
	
	public String toString() {
		return "Insufficient quantity of " + goods.getName();
	}
	
}
