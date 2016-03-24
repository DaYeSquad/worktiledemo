package worktile.com.helloworktile;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.worktilecore.User;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("worktilecore");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 来自 Worktile OpenAPI 的示例 (https://open.worktile.com/wiki/user_info.html#/user)
        // 下一节将会示例 HTTP 请求的方式
        String exampleJson = "{\n" +
                "   \"uid\":\"679efdf3960d45a0b8679693098135ff\",\n" +
                "   \"name\":\"gonglinjie\",\n" +
                "   \"display_name\":\"龚林杰\",\n" +
                "   \"email\":\"gonglinjie@worktile.com\",\n" +
                "   \"desc\":\"\",\n" +
                "   \"avatar\":\"https://api.worktile.com/avatar/80/ae2805fc-9aca-4f3b-8ac4-320c5d664db7.png\",\n" +
                "   \"status\":3,\n" +
                "   \"online\":0\n" +
                "}";
        User user = new User(exampleJson);

        TextView textView = (TextView)findViewById(R.id.example_text_view);
        textView.setText(user.statusDescription());

        // 释放内存 (这里是 NDK 方式在这种设计中比较难受的一个地方，未释放的内存将会造成 Memroy leak)
        // 我们在实际开发中定义所有的 CoreObject 在一个 Activity 中都不要整体的传给第二个 Activity，
        //  而是仅传递 ID, 在第二个 Activity 中，我们通过数据库查询取出对象并且显示 (这些内容将在第二节中提供)
        user.dispose();
    }
}
