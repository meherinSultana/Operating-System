package readerwriter;

public class ReaderWriter {

    public static void main(String[] args) {
        ReadWrite db = new ReadWrite();

        Reader[] rs = new Reader[3];
        Writer[] ws = new Writer[3];

        for (int i = 0; i < 3; i++) {
            rs[i] = new Reader(db, " Reader " + (i + 1));
            rs[i].start();
            ws[i] = new Writer(db, " Writer " + (i + 1));
            ws[i].start();
        }
    }

}
