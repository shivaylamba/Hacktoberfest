import java.util.Arrays;
import java.util.BitSet;

public class Main {

    public static void main(String[] args) throws Exception {

        String str = "abbccda";
        HuffmanEncoder hf = new HuffmanEncoder(str);
        String cs = hf.encode(str);
        System.out.println(cs);
        String ds = hf.decode(cs);
        System.out.println(ds);

        // Bitset is like an array bit at each index it will contain a bit
        // Each component of the bitset has a boolean value. (by default all are false)
        BitSet bitset = new BitSet(cs.length());

        int bitcounter = 0;

        for(Character ch : cs.toCharArray()){
            if (ch.equals('1')){
                bitset.set(bitcounter);
                // set(int bitIndex) :  Sets the bit at the specified index to true.
            }
            bitcounter++;
        }

        for (int i = 0; i < bitset.length(); i++) {
            System.out.print(bitset.get(i) + " ");
        }
        System.out.println(bitset.length());

        byte[] arr = bitset.toByteArray();

        System.out.println(Arrays.toString(arr));
        System.out.println(arr.length);

    }
}
