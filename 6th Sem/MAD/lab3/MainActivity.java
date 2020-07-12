package com.kn.calculator;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    EditText e1, e2;
    TextView t1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        e1 = (EditText) findViewById(R.id.editText1);
        e2 = (EditText) findViewById(R.id.editText2);
        t1 = (TextView) findViewById(R.id.textView);

    }

    public void add(View view) {
        if(TextUtils.isEmpty(e1.getText().toString())|| TextUtils.isEmpty(e2.getText().toString()))
            return;
        int res = Integer.parseInt(e1.getText().toString()) + Integer.parseInt(e2.getText().toString());
        t1.setText(Integer.toString(res));
    }

    public void sub(View view) {
        if(TextUtils.isEmpty(e1.getText().toString())|| TextUtils.isEmpty(e2.getText().toString()))
            return;
        int res = Integer.parseInt(e1.getText().toString()) - Integer.parseInt(e2.getText().toString());
        t1.setText(Integer.toString(res));
    }

    public void mul(View view) {
        if(TextUtils.isEmpty(e1.getText().toString())|| TextUtils.isEmpty(e2.getText().toString()))
            return;
        int res = Integer.parseInt(e1.getText().toString()) * Integer.parseInt(e2.getText().toString());
        t1.setText(Integer.toString(res));
    }

    public void div(View view) {
        if(TextUtils.isEmpty(e1.getText().toString())|| TextUtils.isEmpty(e2.getText().toString()))
            return;
        if (Integer.parseInt(e2.getText().toString())==0)
        {
            t1.setText("Division not possible");
        }
        else
        {
            float res1 = Float.parseFloat(e1.getText().toString())/  Float.parseFloat(e2.getText().toString());
            t1.setText(Float.toString(res1));
        }

    }
}
