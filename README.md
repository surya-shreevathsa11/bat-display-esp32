# bat-display-esp32

This is a compact, WiFi-enabled Batman-themed OLED display that combines a 3D-printed model with a microcontroller to show real-time data and rotating quotes. Perfect for fans and tech enthusiasts, it’s designed to be assembled quickly and easily.

---

### What the Project Does:

* Connects to your **2.4GHz WiFi network** (credentials entered in the code).
* Displays **real-time time, day, and date**, updating every second.
* Shows a **rotating quote** every 5 minutes (currently 500 quotes included, expandable).
* On startup, the **Batman logo** appears, followed by the message **“I’m Batman”**, then the real-time data and quote.
* If WiFi connection fails, it displays an error message.

---

### Hardware:

* **Microcontroller:** ESP32-S3 XIAO from Seeed Studio

  * Super compact and fits easily inside the model.
  * Includes **inbuilt battery charger**, eliminating the need for a separate TP4056 board.
  * Other MCUs like ESP32-WROOM or Arduino are also compatible.
  * **SDA and SCL pins can be changed in the code** according to your board.
  * WiFi credentials can be updated directly in the code.
* **Power:** 3.3V 300mAh battery

  * Connect to **B+ and B- pads** on the ESP32-S3 XIAO.
  * Optional **slide switch** can be added between battery and B+ pad (slot included in CAD model).
* **Display:** 0.96” OLED

  * Connect **3.3V → 3.3V, GND → GND, SDA → configurable, SCL → configurable**.

---

### Assembly Instructions:

1. **Print the model in black** for best aesthetics.
2. Place the ESP32-S3 XIAO and slide switch in their respective CAD slots.
3. Stick the battery to the inner surface using **hot glue** (sufficient room inside the model).
4. Secure the back panel with **M2 screws** and attach the stand with **super glue**.
5. Connect the wiring:

   * 3.3V → 3.3V, GND → GND
   * SDA/SCL → GPIOs as defined in the code (user-adjustable)
   * Battery → B+ and B- (through switch if added)

---

### Room for Improvements:

* Add an **OpenAI API key** to fetch dynamic quotes, weather updates, or even stock prices (fun extra info, not directly Batman-themed).
* Expand the quote list beyond the default 500.
* Experiment with other microcontrollers or battery sizes.

---

This project is ideal for Batman fans, makers, and anyone who enjoys a **stylish, functional, and interactive display**.

---

