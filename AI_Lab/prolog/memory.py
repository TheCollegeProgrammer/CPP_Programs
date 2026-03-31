from pyswip import Prolog

# Initialize Prolog
prolog = Prolog()

# Load Prolog file
prolog.consult("mahabharata.pl")

# -----------------------------
# Queries
# -----------------------------

print("Brothers of Arjuna:")
for result in prolog.query("brother(arjuna, X)"):
    print(result["X"])

print("\nIs Arjuna cousin of Duryodhana?")
result = list(prolog.query("cousin(arjuna, duryodhana)"))
print("Yes" if result else "No")

print("\nAncestors of Arjuna:")
for result in prolog.query("ancestor(X, arjuna)"):
    print(result["X"])

print("\nIs Arjuna disciple of Dronacharya?")
result = list(prolog.query("disciple(arjuna, dronacharya)"))
print("Yes" if result else "No")