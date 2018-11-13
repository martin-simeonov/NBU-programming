
public class Goods {
	private String name;
	private GoodsType type;

	public Goods(String name, GoodsType type) {
		this.name = name;
		this.type = type;
	}

	public Goods() {
		this("", GoodsType.Standard);
	}

	public String getName() {
		return name;
	}

	public GoodsType getType() {
		return type;
	}

}
