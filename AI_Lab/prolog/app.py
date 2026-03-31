import streamlit as st
from pyswip import Prolog

# -----------------------------
# Load Prolog
# -----------------------------
prolog = Prolog()
prolog.consult("mahabharata.pl")

# -----------------------------
# UI
# -----------------------------
st.set_page_config(page_title="Mahabharata AI", page_icon="🧠")

st.title("🧠 Mahabharata Knowledge System")
st.write("Ask relationships like Prolog AI 🔥")

# -----------------------------
# Options
# -----------------------------
option = st.selectbox(
    "Select Query Type",
    [
        "Find Brothers",
        "Check Cousin",
        "Find Ancestors",
        "Check Disciple"
    ]
)

# -----------------------------
# Input
# -----------------------------
name = st.text_input("Enter Character Name (lowercase)", "arjuna")

# -----------------------------
# Logic
# -----------------------------
if st.button("Run Query"):

    if option == "Find Brothers":
        results = list(prolog.query(f"brother({name}, X)"))
        if results:
            st.success("Brothers found:")
            for r in results:
                st.write("👉", r["X"])
        else:
            st.error("No brothers found")

    elif option == "Check Cousin":
        other = st.text_input("Enter Second Character", "duryodhana")
        results = list(prolog.query(f"cousin({name}, {other})"))
        st.success("Yes") if results else st.error("No")

    elif option == "Find Ancestors":
        results = list(prolog.query(f"ancestor(X, {name})"))
        if results:
            st.success("Ancestors:")
            for r in results:
                st.write("👉", r["X"])
        else:
            st.error("No data found")

    elif option == "Check Disciple":
        guru = st.text_input("Enter Guru Name", "dronacharya")
        results = list(prolog.query(f"disciple({name}, {guru})"))
        st.success("Yes") if results else st.error("No")