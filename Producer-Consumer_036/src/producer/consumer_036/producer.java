
package producer.consumer_036;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author User Unknown
 */
public class producer extends Thread {

    private Share buffer;
    private String producerName;
    Scanner sc = new Scanner(System.in);

    public producer(Share buffer, String producerName) {
        this.buffer = buffer;
        this.producerName = producerName;
    }

    @Override
    public void run() {
        try {
            for (int i = 1; i <= 5; i++) {
                System.out.println(producerName + ":Data to insert in the buffer ");
                int item = sc.nextInt();
                buffer.produce(item, producerName);
                sleep(100);
            }
        } catch (InterruptedException ex) {
            Logger.getLogger(producer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
