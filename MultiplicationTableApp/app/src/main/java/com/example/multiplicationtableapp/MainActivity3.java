package com.example.multiplicationtableapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.google.android.material.snackbar.Snackbar;

import java.util.Objects;

public class MainActivity3 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);
//        Objects.requireNonNull(getSupportActionBar()).hide();
    }
    public void onclick(View v){
        Toast.makeText(this, "Data Submitted to Servers", Toast.LENGTH_SHORT).show();
        Snackbar.make(v,"Thank you for using my app",Snackbar.ANIMATION_MODE_SLIDE).show();
    }
}