package com.example.multiplicationtableapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.snackbar.Snackbar;

import java.util.ArrayList;
import java.util.Objects;

public class MainActivity extends AppCompatActivity {
    ListView listView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Objects.requireNonNull(getSupportActionBar()).hide();
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
        TextView textView = findViewById(R.id.textView);
        SeekBar seekBar = findViewById(R.id.seekBar3);
        listView = findViewById(R.id.listview);
        seekBar.setMax(30);
        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
//                Toast.makeText(MainActivity.this, "Populating: " + progress, Toast.LENGTH_SHORT).show();
                populate(progress);
                textView.setText("Multiplication Table of " + progress);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

    }

    public void populate(int table){
        ArrayList<String> mulTable = new ArrayList<>();
        for (int i = 1; i<=10; i++){
             mulTable.add(table + " X " + i + " = " + table*i);
        }
        ArrayAdapter<String> arrayAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1,mulTable);
        listView.setAdapter(arrayAdapter);
    }
    public void onclick(View v){
        Intent intent = new Intent(this,MainActivity2.class);
        startActivity(intent);
    }
}