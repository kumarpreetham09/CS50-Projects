-- Keep a log of any SQL queries you execute as you solve the mystery.

1. SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2021 AND street = "Humphrey Street";
2. SELECT name, transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2021;
3. SELECT activity, license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute > 15 AND minute < 25;
4. SELECT account_number, person_id, creation_year FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location ="Leggett Street" AND transaction_type = "withdraw");
5. SELECT id, caller, receiver FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60;
6. SELECT id, destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = 8 AND day = 29;
7. SELECT passport_number, seat FROM passengers WHERE flight_id = 36;
8. SELECT name, phone_number, license_plate FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 6);
9. SELECT name, license_plate FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60) AND license_plate in (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute > 15 AND minute < 25);
10. SELECT id, name, license_plate, passport_number FROM people
    WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60)
    AND license_plate in (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute > 15 AND minute < 25)
    AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location ="Leggett Street" AND transaction_type = "withdraw"))
    AND passport_number, seat FROM passengers WHERE flight_id = 36;