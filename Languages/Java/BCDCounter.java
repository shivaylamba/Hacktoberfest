import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BCDCounter {
	private SrFlipFlop[] ff = new SrFlipFlop[4];
	private Boolean[] bits = new Boolean[4];
	

	BCDCounter() {
		for (int i = 0; i < 4 ; i++) {
			ff[i] = new SrFlipFlop();
			bits[i] = ff[i].getQ();
		}
	}

	public void print() {
		for (int i = 3; i >= 0 ; i--) {
			if (bits[i])
				System.out.print(1 + " ");
			else
				System.out.print(0 + " ");
		}
		System.out.println();
	}

	public void count() {
		ff[0].operate(!bits[0], bits[0]);

		ff[1].operate( 
			( (!bits[3]) & (!bits[1]) ) & bits[0],
			 bits[1] & bits[0]
			);
		
		ff[2].operate(
			(bits[1] & bits[0]) & !bits[2],
			bits[2] & bits[1] & bits[0]
			);
		
		ff[3].operate(
			bits[2] & bits[1] & bits[0],
			bits[3] & bits[0]
 			);

		for (int i = 0; i < 4 ; i++) {
			bits[i] = ff[i].getQ();
		}
	}

	public Boolean getBit(int i){
		return bits[i];
	}

	public void reset() {
		for (int i = 0; i < 4 ; i++) {
			ff[i].operate(false, true);
			bits[i] = ff[i].getQ();
		}
	}

	public static void main(String[] args) {
		BCDCounter bcdCounter = new BCDCounter();
		Gui gui = new Gui(bcdCounter);
		JFrame frame = gui.draw();		
	}	
}

class SrFlipFlop {
	// Using NOR gate
	private Boolean s,r,q;

	SrFlipFlop() {
		s = false;
		r = false;
		q = false;
	}

	public void operate(Boolean s, Boolean r) {
		this.s = s;
		this.r = r;

		if (s && !r) 
			q = true;

		if (!s && r) 
			q = false;

		else if (s && r) 
			System.out.println("Unstable");
	}

	public Boolean getQ() {
		return q;
	}
}

class Gui {

	private JFrame frame;

	private JLabel[] bitsLabel = new JLabel[4]; 
	private JLabel decimal;
	private JLabel tagDec;
	private JLabel tagBin;

	private JButton counter;
	private JButton reset;

	private BCDCounter bcdCounter;
	private HashMap<Boolean, String> map = new HashMap<Boolean, String>(); 

	private int buttonL = 100;
	private int buttonH = 30;
	private int labelSize = 50;

	Gui(BCDCounter bcdCounter) {
		frame = new JFrame("BCD Counter");

		for (int i = 0; i < 4; i++) {
			bitsLabel[i] = new JLabel("0");
		}
		decimal = new JLabel("0");
		tagDec = new JLabel("Decimal:");
		tagBin = new JLabel("BCD:");

		counter = new JButton("Pulse");
		reset = new JButton("Reset");

		this.bcdCounter = bcdCounter;
		map.put(true, "1");
		map.put(false, "0");
	}

	public JFrame draw() {
		counter.setBounds(70,50,buttonL,buttonH);
		reset.setBounds(70,100,buttonL,buttonH);

		tagDec.setBounds(300, 50, buttonL, buttonH);
		decimal.setBounds(300,100,labelSize,labelSize);

		tagBin.setBounds(250, 350, buttonL, buttonH);
		for (int i = 3; i >= 0 ; i--) {
			bitsLabel[i].setBounds(400 - (i)*100, 400, labelSize, labelSize);
		}
		

		frame.setLayout(null);
		frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
		frame.setSize(500,500);
		frame.setLocationRelativeTo(null);
		
		for(int i = 0; i < 4; i++)
			frame.add(bitsLabel[i]);

		frame.add(tagDec);
		frame.add(tagBin);
		frame.add(decimal);

		frame.add(counter);
		frame.add(reset);
		
		counter.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				countAction();
			}
		});

		reset.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				resetAction();
			}
		});

		frame.setVisible(true);



		return frame;
	}

	public void countAction() {
		bcdCounter.count();
		bcdCounter.print();
		alterDisplay();
	}

	public void resetAction() {
		bcdCounter.reset();
		bcdCounter.print();
		alterDisplay();
	}

	public String getDecimalString() {
		String bitString = "";
		for (int i = 3; i >= 0; i-- ) {
			bitString += map.get(bcdCounter.getBit(i));
		}
		String decimalString = Integer.toString(Integer.parseInt(bitString, 2));
		return decimalString;
	}

	public void alterDisplay() {
		for (int i = 0; i < 4 ; i++ ) {
			bitsLabel[i].setText(map.get(bcdCounter.getBit(i)));
		}
		decimal.setText(getDecimalString());
	}
}
