import React from "react";
import "./contact.css";
import { MdOutlineEmail } from "react-icons/md";
import { AiOutlineLinkedin } from "react-icons/ai";
import { BsWhatsapp } from "react-icons/bs";
import { useRef } from "react";
import emailjs from "emailjs-com";
import { useState } from "react";
import Popup from 'reactjs-popup';
import 'reactjs-popup/dist/index.css';
import axios from "axios";

function Contact() {
  const form = useRef();
  const [input, setInput] = useState({
    avatar: '',
    name: '',
    email: '',
    review: ''
  })

  function handleChange(event) {
    const { name, value } = event.target;

    setInput(prevInput => {
      return {
        ...prevInput,
        [name]: value
      }
    })
  }

  function handleClick(event) {
    event.preventDefault();
    console.log(input);
    const newUser = {
      avatar: input.avatar,
      name: input.name,
      email: input.email,
      review: input.review,
    }
    //Address of the backend server to post our data
    axios.post('http://localhost:3001/create', newUser)
    alert("Review Sent successfully");
  }

  const handleSubmit = (e) => {
    e.preventDefault();
  }

  const sendEmail = (e) => {
    e.preventDefault();
    emailjs.sendForm("service_9u0w2yj", "template_q6gqfpk",
      form.current, "VWzQCS7_dglBVeJJS");
    alert("Message Sent successfully");
    e.target.reset()
      .then((result) => {
        console.log(result.text);
      }, (error) => {
        console.log(error.text);
      });

  };

  const [showPopup, setShowPopup] = useState(false);

  const togglePopup = () => {
    setShowPopup(!showPopup);
  }

  return (
    <section id="contact">
      <h5>Get in touch</h5>
      <h2 className="header_two">Contact me</h2>
      <div className="container contact__container">
        <div className="contact__options">
          <article className="contact__option">
            <MdOutlineEmail className="contact__option__icon" />
            <h4>Email</h4>
            <h5>djeutio1234@gmail.com</h5>
            <a
              href="mailto:djeutio1234@gmail.com"
              target="_blank"
              rel="noreferrer"
            >
              Send a message
            </a>
          </article>
          <article className="contact__option">
            <AiOutlineLinkedin className="contact__option__icon" />
            <h4>LinkedIn</h4>
            <h5>Profile</h5>
            <a
              href="https://www.linkedin.com/in/djeutio-anderson-roy-958b0b234/"
              target="_blank"
              rel="noreferrer"
            >
              Chat on LinkedIn
            </a>
          </article>
          <article className="contact__option">
            <BsWhatsapp className="contact__option__icon" />
            <h4>Whatsapp</h4>
            <h5>Direct message</h5>
            <a
              href="https://web.whatsapp.com/send?phone=+237670780100"
              target="_blank"
              rel="noreferrer"
            >
              Whatsapp me
            </a>
          </article>
        </div>
        <form ref={form} onSubmit={sendEmail}>
          <input type="text" name="name" placeholder="Your Full Name"
            required />
          <input type="email" name="email" placeholder="Your email"
            required />
          <textarea name="message" id="message" cols="30" rows="10"
            placeholder="your message" required></textarea>
          <button type="submit" className="btn btn-primary">
            send message
          </button>

          <Popup trigger={
            <button onClick={togglePopup}
              className="btn btn-primary bt" >Your Review</button>}
            modal nested>{
              close => (
                <div className="main-1">
                  <div className="main-form2">
                    <div className="form2">
                      <form onSubmit={handleSubmit}>
                        <h2 className="GIT">Get in touch</h2>
                        <h4>Aavatar</h4>

                        <input
                          className="Name"
                          type="text"
                          name="avatar"
                          value={input.avatar}
                          autoComplete="off"
                          placeholder="Your image link"
                          onChange={handleChange}
                          required
                        />

                        <h4>First Name</h4>

                        <input
                          className="Name"
                          type="text"
                          name="name"
                          value={input.name}
                          autoComplete="off"
                          placeholder="Name"
                          onChange={handleChange}
                          required
                        />

                        <h4>Email</h4>

                        <input
                          className="email"
                          type="email"
                          name="email"
                          value={input.email}
                          autoComplete="off"
                          placeholder="Email"
                          onChange={handleChange}
                          required
                        />

                        <h4> Your Review </h4>

                        <input
                          className="Role"
                          type="text"
                          value={input.review}
                          required
                          name="review"
                          placeholder="Review"
                          onChange={handleChange}
                        />
                        <button type="submit" onClick={handleClick}
                          className="btn-1 btn-primary-1">
                          Submit</button>
                      </form>
                    </div>
                  </div>
                </div>
              )
            }
          </Popup>
        </form>
      </div>
    </section>
  );
}
export default Contact;
