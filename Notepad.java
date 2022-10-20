import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;

public class Notepad extends JFrame implements ActionListener,Runnable {
JMenuBar mb1;
JMenu mFile,mEdit,mTools,mHelp;
JMenuItem fnew,fopen,fsave,fprint,fexit;
JMenuItem ecut,ecopy,epaste,eselectall;
JMenuItem tcompile,trun,tview;
JMenuItem habout;
JEditorPane jed;
JFileChooser jfc= new JFileChooser();
Thread th1;
public void run() {
	for(;;) {
		try {
			this.setTitle(new java.util.Date().toString());
		}
		catch (Exception ex){
			
		}
	}
}


public Notepad() {
	
	th1=new Thread(this);
	th1.start();
	this.setVisible(true);
	this.setSize(500,500);
	this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	mb1=new JMenuBar();
	mFile= new JMenu("file");
	mEdit=new JMenu("Edit");
	
	mTools= new JMenu("tools");
	mHelp= new JMenu("help");
	fnew= new JMenuItem("new ");
	fopen= new JMenuItem("Open");
	fsave= new JMenuItem("Save");
	fprint= new JMenuItem("print");
	fexit= new JMenuItem("exit");
	
	ecut=new JMenuItem("Cut");
	ecopy=new JMenuItem("Copy");
	epaste=new JMenuItem("Paste");
	eselectall=new JMenuItem("selectall");
	
	tcompile= new JMenuItem("Compile");
	trun=new JMenuItem("Run");
	tview=new JMenuItem("View in browser");
	habout=new JMenuItem("About");
	mFile.add(fnew);mFile.add(fopen);mFile.add(fsave);mFile.add(fprint);mFile.add(fexit);
	mEdit.add(ecut);mEdit.add(ecopy);mEdit.add(epaste);mEdit.add(epaste);mEdit.add(eselectall);
	mTools.add(tcompile);mTools.add(trun);mTools.add(tview);
	mHelp.add(habout);mb1.add(mFile);mb1.add(mEdit);mb1.add(mTools);mb1.add(mHelp);
	this.setJMenuBar(mb1);
	jed=new JEditorPane();
	this.add(jed);
	
	
	
	
	
	
	
	
	fnew.addActionListener(this);
	fopen.addActionListener(this);
	fsave.addActionListener(this);
	fprint.addActionListener(this);
	fexit.addActionListener(this);
	ecut.addActionListener(this);
	ecopy.addActionListener(this);
	epaste.addActionListener(this);
	eselectall.addActionListener(this);
	tcompile.addActionListener(this);
	trun.addActionListener(this);
	tview.addActionListener(this);
	habout.addActionListener(this);
	
	
	
			
}
public void actionPerformed(ActionEvent e) {
	if(e.getSource()==fnew) {
		
	}
	if(e.getSource()==fopen) {
	try {
		jfc.showOpenDialog(null);
		File f=jfc.getSelectedFile();
	//f.delete();
	
	FileInputStream fin= new FileInputStream(f);
	byte data[]=new byte[fin.available()];
	fin.read(data);
	jed.setText(new String(data));
	this.setTitle(f.getAbsolutePath());}
	
	catch(Exception ex) {
		System.out.println(ex);
		
		
	}
	}
	if(e.getSource()==fsave) {
		try {
			jfc.showSaveDialog(this);
			File f=jfc.getSelectedFile();
			FileOutputStream fout=new FileOutputStream(f);
			byte data[]=jed.getText().getBytes();
			fout.write(data);
			fout.flush();
			fout.close();
			this.setTitle(f.getAbsolutePath());
			
		}
		catch(Exception ex) {
			System.out.println("ex");
		}
	}
	if(e.getSource()==fprint) {
		
	}
	if(e.getSource()==fexit) {
		System.exit(0);
		
	}
	if(e.getSource()==ecut) {
		jed.cut();
		
	}
	if(e.getSource()==ecopy) {
		jed.copy();
	}
	if(e.getSource()==epaste) {
		jed.paste();
	}
	if(e.getSource()==eselectall) {
		jed.selectAll();
	}
	if(e.getSource()==tcompile) {
		
	}
	if(e.getSource()==trun) {
		
	}
	if(e.getSource()==tview) {
		
	}
	if(e.getSource()==habout) {
		JOptionPane.showMessageDialog(null,"project developed by \n hy");
	}
}

public static void main(String args[]) {
	new Notepad();
}}
