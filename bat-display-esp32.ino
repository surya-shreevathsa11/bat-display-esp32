#include <WiFi.h>
#include <Wire.h>
#include <time.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <pgmspace.h>

// ==== Wi-Fi Credentials ====
const char* ssid = "wifi_name";           // add your WiFi name inside the double inverted comma
const char* password = "wifi_password";   // add your WiFi name inside the double inverted comma

// ==== OLED Setup ====
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SDA_PIN 21        // change according to your MCU
#define SCL_PIN 19        // change according to your MCU
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ==== Batman Logo Bitmap ====
// 'batlogo (1)', 128x64px
const unsigned char epd_bitmap_batlogo__1_ [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xfc, 0x03, 0xc0, 0x3f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0x87, 0xe1, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// ==== Batman Quotes in PROGMEM ====
const char* const quotes[] PROGMEM = {
  "Sometimes the truth isn't good enough.",
"Fear is a tool. When that light hits the sky, it's a warning.",
"A hero can be anyone.",
"It's not who I am underneath, but what I do that defines me.",
"The night is darkest just before the dawn.",
"Justice is about harmony. Revenge is about making yourself feel better.",
"You either die a hero or live long enough to see yourself become the villain.",
"I wear a mask. And that mask is not to hide who I am.",
"Courage is knowing you'll be licked before you begin, but you begin anyway.",
"I have one power: I never give up.",
"My city needs me.",
"Injustice cannot hide in the shadows.",
"Fear is not an option.",
"Hope is forged in darkness.",
"Vengeance won't heal you.",
"A silent guardian, a watchful protector.",
"Sometimes, the only way to live is to keep moving forward.",
"I work in the shadows to protect the light.",
"Truth can be ugly. That doesn't make it wrong.",
"The world only makes sense if you force it to.",
"People need dramatic examples to shake them out of apathy.",
"I'm whatever Gotham needs me to be.",
"Heroes are made by the paths they choose, not the powers they are graced with.",
"I believe in Gotham. I believe in her people.",
"Sometimes the best way to solve your own problems is to help someone else.",
"The mask you wear says more about who you are than what you hide.",
"In a world full of monsters, be the light that frightens them away.",
"Fear can keep us focused. Fear can motivate us.",
"A symbol is more powerful than a weapon.",
"Justice isn't about revenge; it's about balance.",
"Sometimes pain is the only thing that makes you feel alive.",
"The greatest weapon against fear is hope.",
"A true hero fights for what's right, not for recognition.",
"I don't kill because I'm better than that.",
"Every night I fight to make sure no one else suffers.",
"Darkness falls across the land, but I am the light.",
"Being a hero isn't about glory. It's about sacrifice.",
"The city needs its guardian, even if it doesn't know it.",
"Justice isn't blind—it sees everything.",
"The bat is a creature of the night, but it also brings clarity.",
"Sometimes you have to lose yourself to find your true purpose.",
"You can't save everyone, but you have to try.",
"Justice is a choice we make every day.",
"Heroes don't give up when things get tough.",
"Fear can be a weapon, but it can also be a shield.",
"Sometimes the hardest battles are fought within.",
"The mask hides the man, but not the mission.",
"A symbol can inspire hope where words fail.",
"The night is full of secrets, but so is the heart.",
"The darkest nights produce the brightest stars.",
"Sometimes being a hero means being misunderstood.",
"Justice is a flame that must never be extinguished.",
"Every scar tells a story of survival.",
"You can't outrun your past, but you can shape your future.",
"Strength is not just muscle, but will.",
"The city is my responsibility, not just my home.",
"Sometimes the best defense is a strong offense.",
"Heroes don't seek fame; they seek justice.",
"The night is long, but dawn always comes.",
"Fear can drive us to greatness or destroy us.",
"Justice is the balance between order and chaos.",
"Sometimes the only way forward is through the darkness.",
"Hope is the light that guides us home.",
"The bat teaches us to face our fears.",
"You donvt have to be perfect to be a hero.",
"Every night I choose to fight, not flee.",
"The city's shadows hide many secrets.",
"Justice is the sword and shield of the innocent.",
"The darkest hour is just before the dawn.",
"Sometimes you have to fight alone to protect many.",
"Fear can be conquered, but never ignored.",
"Heroes aren't born, they're made.",
"The night reveals what daylight conceals.",
"Justice is the promise we keep to ourselves.",
"Sometimes strength lies in knowing when to let go.",
"The bat is a symbol of fear turned into hope.",
"Every hero has a past they wish to forget.",
"The city is my fortress, and I am its guardian.",
"Sometimes the greatest battle is within the soul.",
"Justice is not a destination but a journey.",
"Fear is a shadow; courage is the light.",
"Heroes stand when others fall.",
"The night is a canvas for justice.",
"Sometimes the truth is hidden in darkness.",
"Justice is a beacon in the night.",
"Every night I rise to protect the innocent.",
"Fear can sharpen your senses.",
"Heroes fight for the silent and unseen.",
"The city's heartbeat is in the shadows.",
"Justice is the voice of the voiceless.",
"Sometimes the only way to win is to fight for what's right.",
"The bat is a reminder that fear can be overcome.",
"Every night is a new battle.",
"The night belongs to those who dare.",
"Justice is the armor of the righteous.",
"Fear is a test of your will.",
"Heroes inspire hope in the hopeless.",
"The city needs a guardian, not a savior.",
"Sometimes the hardest fight is against yourself.",
"Justice is the sword that cuts through lies.",
"Fear is the fire that forges strength.",
"Heroes don't wear capes, they wear courage.",
"The night is a cloak for justice.",
"Sometimes the darkest souls bring the most light.",
"Justice is the shield that protects the innocent.",
"Every night I fight for Gotham's future.",
"Fear is a challenge to overcome.",
"Heroes rise when the world falls.",
"The city's soul is worth protecting.",
"Justice is a promise kept in darkness.",
"Sometimes the greatest strength is in mercy.",
"The bat is a symbol of resilience.",
"Every night I stand against the night.",
"Fear can be your greatest teacher.",
"Heroes fight not for glory but for peace.",
"The night is a stage for justice.",
"Sometimes you have to become the darkness to fight it.",
"Justice is a flame that never dies.",
"Fear is the enemy within.",
"Heroes protect the broken and the lost.",
"The city's shadows are my battlefield.",
"Justice is the light in the abyss.",
"Every night is a fight for hope.",
"Fear sharpens the mind and heart.",
"Heroes rise in the face of fear.",
"The night is a friend to the vigilant.",
"Sometimes the hardest choice is the right one.",
"Justice is the strength of the oppressed.",
"Fear can be the path to courage.",
"Heroes stand for what others cannot.",
"The city is a fortress of hope.",
"Justice is the law of the brave.",
"Sometimes the only way to save is to sacrifice.",
"The bat is a guardian of the night.",
"Every night I face the darkness within.",
"Fear is the first step to courage.",
"Heroes fight for those who cannot fight.",
"The night is a canvas for the brave.",
"Sometimes justice means breaking the rules.",
"Justice is the light that never fades.",
"Fear can make us stronger.",
"Heroes protect the innocent with their lives.",
"The city needs its bat more than ever.",
"Justice is the voice of the night.",
"Sometimes the hardest battles are the most important.",
"The bat is the symbol of hope in darkness.",
"Every night I fight for what's right.",
"Fear is a lesson in disguise.",
"Heroes don't quit when it's hard.",
"The night hides many secrets, but justice reveals them.",
"Sometimes you have to be the shadow to protect the light.",
"Justice is the path to peace.",
"Fear can be the key to survival.",
"Heroes stand tall when others fall.",
"The city's soul is worth the fight.",
"Justice is the light in the darkness.",
"Sometimes the strongest people are the ones who fight alone.",
"The bat teaches us to face fear head-on.",
"Every night I rise for justice.",
"Fear is the fire that fuels the brave.",
"Heroes fight for the forgotten.",
"The night is a shield for the righteous.",
"Sometimes justice requires sacrifice.",
"Justice is the hope of the oppressed.",
"Fear is a challenge to be met.",
"Heroes stand for what's right, no matter the cost.",
"The city is my home, and I protect it.",
"Justice is the sword of truth.",
"Sometimes the only way to win is to never give up.",
"The bat is a symbol of unwavering resolve.",
"Every night I fight for Gotham's peace.",
"Fear can be overcome with courage.",
"Heroes rise to meet the darkness.",
"The night is a battleground for justice.",
"Sometimes justice is the hardest path.",
"Justice is the light that guides us.",
"Fear is a test of strength.",
"Heroes protect the innocent and weak.",
"The city needs a symbol of hope.",
"Justice is the shield against chaos.",
"Sometimes you have to fight alone.",
"The bat is a beacon in the night.",
"Every night I stand against evil.",
"Fear is the first hurdle to overcome.",
"Heroes fight for those who cannot.",
"The night is a cloak for the brave.",
"Sometimes justice means facing your fears.",
"Justice is the sword that protects.",
"Fear is the enemy of hope.",
"Heroes stand when all else falls.",
"The city's shadows hide many dangers.",
"Justice is the promise of safety.",
"Sometimes the greatest strength is kindness.",
"The bat symbolizes resilience and hope.",
"Every night I protect Gotham's streets.",
"Fear can be conquered by will.",
"Heroes fight for peace and justice.",
"The night is a shield for the innocent.",
"Sometimes justice requires courage.",
"Justice is the voice of the weak.",
"Fear is a challenge to face.",
"Heroes protect the vulnerable.",
"The city's heart beats in the shadows.",
"Justice is the sword of the brave.",
"Sometimes the hardest fight is for what's right.",
"The bat is a symbol of courage.",
"Every night I stand for justice.",
"Fear is the shadow of courage.",
"Heroes fight in the darkest hours.",
"The night is a refuge for justice.",
"Sometimes justice means sacrifice.",
"Justice is the light in the dark.",
"Fear is the test of strength.",
"Heroes protect the innocent at all costs.",
"The city needs its guardian.",
"Justice is the shield of the oppressed.",
"Sometimes you have to stand alone.",
"The bat is the symbol of hope.",
"Every night I fight for Gotham.",
"Fear can be overcome with courage.",
"Heroes rise when darkness falls.",
"The night is a battlefield for justice.",
"Sometimes justice is hard to find.",
"Justice is the light in darkness.",
"Fear is a challenge to overcome.",
"Heroes protect those who cannot protect themselves.",
"The city's soul is worth saving.",
"Justice is the promise of safety.",
"Sometimes the greatest strength is forgiveness.",
"The bat symbolizes hope and resilience.",
"Every night I protect the innocent.",
"Fear can be defeated by will.",
"Heroes fight for peace and justice.",
"The night is a shield for the helpless.",
"Sometimes justice requires sacrifice.",
"Justice is the voice of the weak.",
"Fear is a test to overcome.",
"Heroes stand for what's right.",
"The city's shadows hide many secrets.",
"Justice is the sword of truth.",
"Sometimes the hardest battles are the most important.",
"The bat is a beacon of hope.",
"Every night I rise for justice.",
"Fear is the fire that fuels the brave.",
"Heroes fight for the forgotten.",
"The night is a shield for the righteous.",
"Sometimes justice means breaking the rules.",
"Justice is the light that never fades.",
"Fear can make us stronger.",
"Heroes protect the innocent with their lives.",
"The city needs its bat more than ever.",
"Justice is the voice of the night.",
"Sometimes the hardest battles are the most important.",
"The bat is the symbol of hope in darkness.",
"Every night I fight for what's right.",
"Fear is a lesson in disguise.",
"Heroes don't quit when it's hard.",
"The night hides many secrets, but justice reveals them.",
"Sometimes you have to be the shadow to protect the light.",
"Justice is the path to peace.",
"Fear can be the key to survival.",
"Heroes stand tall when others fall.",
"The city's soul is worth the fight.",
"Justice is the light in the darkness.",
"Sometimes the strongest people are the ones who fight alone.",
"The bat teaches us to face fear head-on.",
"Every night I rise for justice.",
"Fear is the fire that fuels the brave.",
"Heroes fight for the forgotten.",
"The night is a shield for the righteous.",
"Sometimes justice requires sacrifice.",
"Justice is the hope of the oppressed.",
"Fear is a challenge to be met.",
"Heroes stand for what's right, no matter the cost.",
"The city is my home, and I protect it.",
"Justice is the sword of truth.",
"Sometimes the only way to win is to never give up.",
"The bat is a symbol of unwavering resolve.",
"Every night I fight for Gotham's peace.",
"Fear can be overcome with courage.",
"Heroes rise to meet the darkness.",
"The night is a battleground for justice.",
"Sometimes justice is the hardest path.",
"Justice is the light that guides us.",
"Fear is a test of strength.",
"Heroes protect the innocent and weak.",
"The city needs a symbol of hope.",
"Justice is the shield against chaos.",
"Sometimes you have to fight alone.",
"The bat is a beacon in the night.",
"Every night I stand against evil.",
"Fear is the first hurdle to overcome.",
"Heroes fight for those who cannot.",
"The night is a cloak for the brave.",
"Sometimes justice means facing your fears.",
"Justice is the sword that protects.",
"Fear is the enemy of hope.",
"Heroes stand when all else falls.",
"The city's shadows hide many dangers.",
"Justice is the promise of safety.",
"Sometimes the greatest strength is kindness.",
"The bat symbolizes resilience and hope.",
"Every night I protect Gotham's streets.",
"Fear can be conquered by will.",
"Heroes fight for peace and justice.",
"The night is a shield for the innocent.",
"Sometimes justice requires courage.",
"Justice is the voice of the weak.",
"Fear is a challenge to face.",
"Heroes protect the vulnerable.",
"The city's heart beats in the shadows.",
"Justice is the sword of the brave.",
"Sometimes the hardest fight is for what's right.",
"The bat is a symbol of courage.",
"Every night I stand for justice.",
"Fear is the shadow of courage.",
"Heroes fight in the darkest hours.",
"The night is a refuge for justice.",
"Sometimes justice means sacrifice.",
"Justice is the light in the dark.",
"Fear is the test of strength.",
"Heroes protect the innocent at all costs.",
"The city needs its guardian.",
"Justice is the shield of the oppressed.",
"Sometimes you have to stand alone.",
"The bat is the symbol of hope.",
"Every night I fight for Gotham.",
"Fear can be overcome with courage.",
"Heroes rise when darkness falls.",
"The night is a battlefield for justice.",
"Sometimes justice is hard to find.",
"Justice is the light in darkness.",
"Fear is a challenge to overcome.",
"Heroes protect those who cannot protect themselves.",
"The city's soul is worth saving.",
"Justice is the promise of safety.",
"Sometimes the greatest strength is forgiveness.",
"The bat symbolizes hope and resilience.",
"Every night I protect the innocent.",
"Fear can be defeated by will.",
"Heroes fight for peace and justice.",
"The night is a shield for the helpless.",
"Sometimes justice requires sacrifice.",
"Justice is the voice of the weak.",
"Fear is a test to overcome.",
"Heroes stand for what's right.",
"The city's shadows hide many secrets.",
"Justice is the sword of truth.",
"Sometimes the hardest battles are the most important.",
"The bat is a beacon of hope.",
"Every night I rise for justice.",
"Fear is the fire that fuels the brave.",
"Heroes fight for the forgotten.",
"The night is a shield for the righteous.",
"Sometimes justice means breaking the rules.",
"Justice is the light that never fades.",
"Fear can make us stronger.",
"Heroes protect the innocent with their lives.",
"The city needs its bat more than ever.",
"Justice is the voice of the night.",
"Sometimes the hardest battles are the most important."



};
const int quoteCount = sizeof(quotes) / sizeof(quotes[0]);
int quoteOrder[quoteCount];
int quoteIndex = 0;
int lastQuoteMinute = -5;

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Connecting WiFi...");
  display.display();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("WiFi connected");
  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();
  delay(1000); // space for GIF

  showBatlogo(); // Show batman logo before "I'm Batman"

  showBatman();
  configTime(19800, 0, "pool.ntp.org");
  while (!getLocalTime(new tm)) delay(500);

  // Shuffle quotes
  for (int i = 0; i < quoteCount; i++) quoteOrder[i] = i;
  for (int i = 0; i < quoteCount; i++) {
    int j = random(quoteCount);
    int t = quoteOrder[i];
    quoteOrder[i] = quoteOrder[j];
    quoteOrder[j] = t;
  }

  showQuoteScreen();
}

void loop() {
  static unsigned long lastSecondUpdate = 0;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) return;

  unsigned long nowMillis = millis();

  // === Update clock every second ===
  if (nowMillis - lastSecondUpdate >= 1000) {
    lastSecondUpdate = nowMillis;

    char timeStr[10];
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);

    display.fillRect(0, 0, 60, 8, SSD1306_BLACK); // Clear time area
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print(timeStr);
    display.display();
  }

  // === Quote change every 5 minutes ===
  int currentMinute = timeinfo.tm_min;
  if ((currentMinute % 5 == 0) && (currentMinute != lastQuoteMinute)) {
    lastQuoteMinute = currentMinute;
    quoteIndex = (quoteIndex + 1) % quoteCount;
    showQuoteScreen();
  }
}

// Show batman logo before "I'm Batman"
void showBatlogo() {
  display.clearDisplay();
  display.drawBitmap(0, 0, epd_bitmap_batlogo__1_, 128, 64, SSD1306_WHITE);
  display.display();
  delay(2000); // Show logo for 2 seconds
  display.clearDisplay();
  display.display();
  delay(200);
}

void showBatman() {
  const char* msg = "I'm Batman";
  display.clearDisplay();
  display.setTextSize(1);
  int x = (SCREEN_WIDTH - strlen(msg) * 6) / 2;
  int y = (SCREEN_HEIGHT - 8) / 2;
  for (int i = 0; i <= strlen(msg); i++) {
    display.clearDisplay();
    display.setCursor(x, y);
    for (int j = 0; j < i; j++) {
      display.print(msg[j]);
    }
    display.display();
    delay(75);
  }
  delay(2000);
}

void showQuoteScreen() {
  display.clearDisplay();
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) return;

  // Top row: Time & Vigilante
  char timeStr[10];
  strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(timeStr);

  const char* tag = "Vigilante";
  display.setCursor(SCREEN_WIDTH - strlen(tag) * 6, 0);
  display.print(tag);

  // Second row: Date & Day
  char dateStr[12];
  strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", &timeinfo);
  display.setCursor(0, 10);
  display.print(dateStr);

  char dayStr[4];
  strftime(dayStr, sizeof(dayStr), "%a", &timeinfo);
  display.setCursor(SCREEN_WIDTH - strlen(dayStr) * 6, 10);
  display.print(dayStr);

  // Fetch quote from PROGMEM
  char quote[160];
  strncpy_P(quote, (PGM_P)pgm_read_ptr(&(quotes[quoteOrder[quoteIndex]])), sizeof(quote));
  quote[sizeof(quote) - 1] = '\0';

  // Word-wrap and fade in
  int y = 25;
  String word = "", line = "";
  for (int i = 0; i <= strlen(quote); i++) {
    char c = quote[i];
    if (c == ' ' || c == '\0') {
      int width = (line.length() + word.length()) * 6;
      if (width > SCREEN_WIDTH) {
        fadeLine(line, y);
        y += 10;
        line = word + " ";
      } else {
        line += word + " ";
      }
      word = "";
    } else {
      word += c;
    }
  }
  if (line.length()) fadeLine(line, y);
  display.display();
}

void fadeLine(String line, int y) {
  for (int i = 0; i <= line.length(); i++) {
    display.setCursor(0, y);
    display.print(line.substring(0, i));
    display.display();
    delay(20);
  }
}