-- Keep a log of any SQL queries you execute as you solve the mystery.

1. SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2021 AND street = "Humphrey Street";
2. SELECT name, transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2021;
3. SELECT activity, license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute > 15 AND minute < 25;
4. SELECT account_number, person_id, creation_year FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location ="Leggett Street" AND transaction_type = "withdraw");
5. SELECT id, caller, receiver FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60;
6. SELECT destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = 8 AND day = 28;
7.