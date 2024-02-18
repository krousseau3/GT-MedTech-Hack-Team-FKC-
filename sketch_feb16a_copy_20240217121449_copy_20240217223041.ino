void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(7, OUTPUT);

  // INPUTS (example values):
  double weight = 160; // lbs
  double meal_carb_count = 60; // carbs
  double blood_sugar_actual = 220; // mg/dl, amt you're at
  double blood_sugar_target = 120; // mg/dl, amt you want
  char dosage_type[] = "HBS"; // "basal", "HBS", or "CHO"

  // CODE 1: DETERMING DOSAGE VALUES:
  double TDR = weight / 4;

  double basalDOSE = TDR / 45; // steady stream throughout the day
  double carb_coverage_ratio = 500 / TDR; // 1 unit insulin covers this many grams carb, NOT THE DOSE
  double HBS_correction_factor = 1800 / TDR; // 1 unit insulin drops blood sugar level by this much mg/dl, NOT THE DOSE

  double doseCHO = meal_carb_count / carb_coverage_ratio; // dosage for carb coverage (meals)

  double blood_sugar_diff = blood_sugar_actual - blood_sugar_target;
  double doseHBS = blood_sugar_diff / HBS_correction_factor; // dosage for high blood sugar

  Serial.println("--- new run below ---");
  Serial.print("weight is ");
  Serial.println(weight);

  // CODE 2: DETERMINING GEAR ROTS GIVEN DOSAGES. How much insulin is moved by a unit of rotation?

  

  // CODE 3: ROTATING THE MOTORS

  // me testing stuff
  digitalWrite(13, HIGH);
  digitalWrite(7, HIGH);
  delay(weight * 50);
  digitalWrite(13, LOW);
  digitalWrite(7, LOW);


}

void loop() {
  // put your main code here, to run repeatedly:

  //digitalWrite(13, HIGH);
  //delay(1250); // 1250 IS NOT EXACT TIME FOR 1 ROT
  //digitalWrite(13, LOW);
  //delay(1000);
  
}


