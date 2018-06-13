import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class MainClass {

	public static void main(String args[]) {
		Goods goods = new Goods("Cheese", 5, 20);
		try {
			FileOutputStream fos = new FileOutputStream("goods.ser");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			oos.writeObject(goods);

			oos.close();
			fos.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		Goods deserializedGoods = null;
		try {
			FileInputStream fis = new FileInputStream("goods.ser");
			ObjectInputStream ois = new ObjectInputStream(fis);
			deserializedGoods = (Goods) ois.readObject();

			ois.close();
			fis.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		if (deserializedGoods != null)
			System.out.println(deserializedGoods.getName());
		
		Company recipient = new Company("Rest", 2);
		Store store = new Store(deserializedGoods, 5, new Company("Vitosha", 1), new ArrayList<Company>());
		try {
			store.sellGoods(6, recipient);
		} catch (InsufficientQuantityOfGoodsException e) {
			System.out.println(e);
		}
		
		try {
			Invoice invoice = store.sellGoods(3, recipient);
			String file = store.writeInvoiceToFile(invoice);
			store.readInvoiceFromFile(file);
		} catch (InsufficientQuantityOfGoodsException e) {
			System.out.println(e);
		}
		
	}

}
