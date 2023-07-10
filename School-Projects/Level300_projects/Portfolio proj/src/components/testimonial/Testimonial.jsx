import React, { useEffect, useState } from "react";
import "./testimonial.css";
import axios from "axios";

// import Swiper core and required modules
import { Pagination, Navigation, Scrollbar, A11y } from "swiper";
import { Swiper, SwiperSlide } from "swiper/react";

// Import Swiper styles
import "swiper/css";
import "swiper/css/pagination";

export const Testimonial = () => {
  const [data, setData] = useState([]);
  useEffect (()=>{
    axios.get("http://localhost:8000/api/testimonial")
    .then(resp => {
      const formattedData = resp.data.data.map(item =>({
        id:item._id,
        avatar: item.avatar,
        Cname: item.name,
        testimonial: item.review
      }));
      setData(formattedData)
    })
    .catch(error =>{
      console.log('Error fetching Testimonial Data ', error);
    })
  },[])
  return (
    <section id="testimonial">
      <h5>Review from client</h5>
      <h2 className="header_two">Testimonials</h2>

      <Swiper
        className="container testimonials__container"
        modules={[Pagination, Navigation, Scrollbar, A11y]}
        spaceBetween={30}
        slidesPerView={1}
        pagination={{ clickable: true }}
      >
        {data.map((testi) => {
          return (
            <SwiperSlide key={testi.id} className="testimonial">
              <div className="client__avatar">
                <img src={testi.avatar} alt="client avatar" />
              </div>
              <h5 className="client__name"> {testi.Cname} </h5>
              <small className="client__review"> {testi.testimonial} </small>
            </SwiperSlide>
          );
        })}
      </Swiper>
    </section>
  );
};
export default Testimonial;
