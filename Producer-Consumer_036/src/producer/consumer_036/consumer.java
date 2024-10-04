package producer.consumer_036;

import static java.lang.Thread.sleep;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author User Unknown
 */
public class consumer extends Thread {

    private Share buffer;
    private String consumerName;

    public consumer(Share buffer, String consumerName) {
        this.buffer = buffer;
        this.consumerName = consumerName;
    }

    @Override
    public void run() {

        try {
            for (int i = 1; i <= 5; i++) {
                buffer.consume(consumerName);
                sleep(200);

            }
        } catch (InterruptedException ex) {
            Logger.getLogger(consumer.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
}
