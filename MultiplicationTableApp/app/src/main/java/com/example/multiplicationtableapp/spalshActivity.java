package com.example.multiplicationtableapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.WindowManager;
import android.widget.Toast;

import java.util.Objects;

public class spalshActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_spalsh);
        Objects.requireNonNull(getSupportActionBar()).hide();
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);

        Thread td = new Thread() {
            public void run() {
                try {

                    sleep(10000);

                } catch (Exception e) {
                    e.printStackTrace();
                } finally {
                    Intent intent = new Intent(spalshActivity.this,MainActivity.class);
                    startActivity(intent);
                    finish();
//                    Toast.makeText(MainActivity.this, "Boosted Multiplication Tables App", Toast.LENGTH_SHORT).show();

                }
            }
        };td.start();

    }

}