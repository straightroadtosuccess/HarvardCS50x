-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';


SELECT *
FROM interviews
WHERE transcript LIKE '%bakery%';


SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;


SELECT p.name, bsl.activity, bsl.license_plate, bsl.month, bsl.day, bsl.hour, bsl.minute
FROM bakery_security_logs bsl
JOIN people p ON p.license_plate = bsl.license_plate
WHERE bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 25;




SELECT *
FROM atm_transactions
WHERE atm_location = 'Leggett Street'
AND month = 7 AND day = 28;



SELECT a.*, p.name
FROM atm_transactions a
JOIN bank_accounts b ON a.account_number = b.account_number
JOIN people p ON b.person_id = p.id
WHERE a.atm_location = 'Leggett Street' AND month = 7 AND day = 28 AND a.transaction_type = 'withdraw';

-- witness 3 phone call investigation
SELECT *
FROM phone_calls
WHERE month = 7 AND day = 28 AND duration < 60;

-- add names to call list
SELECT p.name, pc.caller, pc.month, pc.day, pc.duration
FROM phone_calls pc
JOIN people p ON pc.caller = p.phone_number
WHERE pc.month = 7 AND pc.day = 28 AND pc.duration < 60;

-- explore airports to identify fiftyville
SELECT *
FROM airports;

-- found fifty id 8, flight out 36
SELECT flights.*, origin.full_name AS origin_airport, destination.full_name AS destination_airport
FROM flights
JOIN airports AS origin ON flights.origin_airport_id = origin.id
JOIN airports AS destination ON flights.destination_airport_id = destination.id
WHERE origin.id = 8 AND flights.month = 7 AND flights.day = 29;

--combine info from all three testimonies
SELECT p.name
FROM bakery_security_logs bsl
JOIN people p ON p.license_plate = bsl.license_plate
JOIN bank_accounts ba ON ba.person_id = p.id
JOIN atm_transactions at ON at.account_number = ba.account_number
JOIN phone_calls pc ON pc.caller = p.phone_number
WHERE bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 25
AND at.atm_location = 'Leggett Street' AND at.month = 7 AND at.day = 28 AND at.transaction_type
= 'withdraw' AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;

--narrow down from bruce/diana
SELECT p.name
FROM people p
JOIN passengers ps ON p.passport_number = ps.passport_number
WHERE ps.flight_id = 36
AND p.name IN ('Bruce', 'Diana');


--who did bruce call--
SELECT p2.name AS receiver
FROM phone_calls pc
JOIN people p1 ON pc.caller = p1.phone_number
JOIN people p2 ON pc.receiver = p2.phone_number
WHERE p1.name = 'Bruce' AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;
