-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get description of the crime scene
SELECT description
FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- Get transcripts of theree witnesses' interviews
SELECT *
FROM interviews
WHERE transcript LIKE '%bakery%';

-- Determine suspects from testimonies
SELECT DISTINCT people.name
FROM people
    JOIN bank_accounts
    ON people.id = bank_accounts.person_id
WHERE people.license_plate IN
    (SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25
    AND activity = 'exit')
AND bank_accounts.account_number IN
    (SELECT account_number
    FROM atm_transactions
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw')
AND people.phone_number IN
    (SELECT caller
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60);

-- Determine the city the thief escaped to
SELECT flights.hour, flights.minute, airports.city AS destination_city
FROM airports
    JOIN flights
    ON flights.destination_airport_id = airports.id
WHERE year = 2021
AND month = 7
AND day = 29
AND
    (SELECT airports.city FROM airports
    JOIN flights
    ON flights.origin_airport_id = airports.id
    WHERE year = 2021
    AND month = 7
    AND day = 29)
= 'Fiftyville'
ORDER BY flights.hour;

-- Determine the thief
SELECT people.name
FROM people
    JOIN passengers, flights, airports
    ON people.passport_number = passengers.passport_number
    AND passengers.flight_id = flights.id
    AND flights.destination_airport_id = airports.id
WHERE flights.year = 2021
AND flights.month = 7
AND flights.day = 29
AND flights.hour = 8
AND flights.minute = 20
AND airports.city = 'New York City';

-- Determine his accomplice
SELECT name
FROM people
WHERE phone_number IN
    (SELECT receiver
    FROM phone_calls
        JOIN people
        ON phone_calls.caller = people.phone_number
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
    AND people.name = 'Bruce');
