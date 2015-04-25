void enterSleep(void)
{
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);   /* EDIT: could also use SLEEP_MODE_PWR_DOWN for lowest power consumption. */
  Serial.println("Entering Sleep Mode");
  delay(100);
  radio.powerDown();
  sleep_enable();
  
  /* Now enter sleep mode. */
  sleep_mode();
  
  /* The program will continue from here after the WDT timeout*/
  sleep_disable(); /* First thing to do is disable sleep. */
  
  /* Re-enable the peripherals. */
  power_all_enable();
  radio.powerUp();
  Serial.println("Exiting Sleep Mode");
  delay(100);
}


ISR(WDT_vect)
{
  WatchDog_Counter+=1;
}


