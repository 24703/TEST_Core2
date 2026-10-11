#include <M5Unified.h>

// 初期設定 ----------------------------------------------------
void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);                       // 本体初期化

  M5.Display.setTextColor(YELLOW);     // 文字色
  M5.Display.setTextSize(2);           // 文字サイズ
  M5.Display.setCursor(65, 10);        // 座標指定
  M5.Display.println("Button example");
  M5.Display.setCursor(3, 35);         // 座標指定
  M5.Display.println("Press button B for 700ms");
  M5.Display.println("to clear screen.");
  M5.Display.setTextColor(RED);        // 文字色
}

// メイン ------------------------------------------------------
void loop() {
  M5.update();                         // ボタン状態更新
  
  // 【解説】wasPressed（1回押した）または pressedFor(1000)（1秒以上押しっぱなし中）
  if (M5.BtnA.wasPressed() || M5.BtnA.pressedFor(1000)) {
    M5.Display.print('A');                                                                                   
  } 
  else if (M5.BtnB.pressedFor(1000) || M5.BtnB.wasPressed()) {
    // 💡注意: 先に長押しのクリア判定（wasReleaseFor）に引っかからないよう、BtnBは通常処理をさせます
    M5.Display.print('B');                                                                                    
  } 
  else if (M5.BtnC.wasPressed() || M5.BtnC.pressedFor(1000)) {
    M5.Display.print('C');                                                                                 
  } 
  else if (M5.BtnB.wasReleaseFor(700)) {                            // BtnBが0.7秒以上押されて離したら
    M5.Display.clear(WHITE);           // 画面白クリア
    M5.Display.setCursor(0, 0);        // 座標指定
  }
  
  delay(80);  // 遅延時間（ 連打速度の間隔）
}
