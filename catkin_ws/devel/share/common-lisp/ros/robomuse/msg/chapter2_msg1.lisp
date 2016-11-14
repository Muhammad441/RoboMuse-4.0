; Auto-generated. Do not edit!


(cl:in-package robomuse-msg)


;//! \htmlinclude chapter2_msg1.msg.html

(cl:defclass <chapter2_msg1> (roslisp-msg-protocol:ros-message)
  ((A
    :reader A
    :initarg :A
    :type cl:integer
    :initform 0)
   (B
    :reader B
    :initarg :B
    :type cl:integer
    :initform 0)
   (th
    :reader th
    :initarg :th
    :type cl:integer
    :initform 0)
   (vx
    :reader vx
    :initarg :vx
    :type cl:integer
    :initform 0)
   (vy
    :reader vy
    :initarg :vy
    :type cl:integer
    :initform 0)
   (vth
    :reader vth
    :initarg :vth
    :type cl:integer
    :initform 0))
)

(cl:defclass chapter2_msg1 (<chapter2_msg1>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <chapter2_msg1>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'chapter2_msg1)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robomuse-msg:<chapter2_msg1> is deprecated: use robomuse-msg:chapter2_msg1 instead.")))

(cl:ensure-generic-function 'A-val :lambda-list '(m))
(cl:defmethod A-val ((m <chapter2_msg1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robomuse-msg:A-val is deprecated.  Use robomuse-msg:A instead.")
  (A m))

(cl:ensure-generic-function 'B-val :lambda-list '(m))
(cl:defmethod B-val ((m <chapter2_msg1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robomuse-msg:B-val is deprecated.  Use robomuse-msg:B instead.")
  (B m))

(cl:ensure-generic-function 'th-val :lambda-list '(m))
(cl:defmethod th-val ((m <chapter2_msg1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robomuse-msg:th-val is deprecated.  Use robomuse-msg:th instead.")
  (th m))

(cl:ensure-generic-function 'vx-val :lambda-list '(m))
(cl:defmethod vx-val ((m <chapter2_msg1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robomuse-msg:vx-val is deprecated.  Use robomuse-msg:vx instead.")
  (vx m))

(cl:ensure-generic-function 'vy-val :lambda-list '(m))
(cl:defmethod vy-val ((m <chapter2_msg1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robomuse-msg:vy-val is deprecated.  Use robomuse-msg:vy instead.")
  (vy m))

(cl:ensure-generic-function 'vth-val :lambda-list '(m))
(cl:defmethod vth-val ((m <chapter2_msg1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robomuse-msg:vth-val is deprecated.  Use robomuse-msg:vth instead.")
  (vth m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <chapter2_msg1>) ostream)
  "Serializes a message object of type '<chapter2_msg1>"
  (cl:let* ((signed (cl:slot-value msg 'A)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'B)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'th)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'vx)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'vy)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'vth)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <chapter2_msg1>) istream)
  "Deserializes a message object of type '<chapter2_msg1>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'A) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'B) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'th) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vx) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vy) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vth) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<chapter2_msg1>)))
  "Returns string type for a message object of type '<chapter2_msg1>"
  "robomuse/chapter2_msg1")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'chapter2_msg1)))
  "Returns string type for a message object of type 'chapter2_msg1"
  "robomuse/chapter2_msg1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<chapter2_msg1>)))
  "Returns md5sum for a message object of type '<chapter2_msg1>"
  "1b257d9da54433962cd96747b8ec421c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'chapter2_msg1)))
  "Returns md5sum for a message object of type 'chapter2_msg1"
  "1b257d9da54433962cd96747b8ec421c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<chapter2_msg1>)))
  "Returns full string definition for message of type '<chapter2_msg1>"
  (cl:format cl:nil "int32 A~%int32 B~%int32 th~%int32 vx~%int32 vy~%int32 vth~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'chapter2_msg1)))
  "Returns full string definition for message of type 'chapter2_msg1"
  (cl:format cl:nil "int32 A~%int32 B~%int32 th~%int32 vx~%int32 vy~%int32 vth~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <chapter2_msg1>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <chapter2_msg1>))
  "Converts a ROS message object to a list"
  (cl:list 'chapter2_msg1
    (cl:cons ':A (A msg))
    (cl:cons ':B (B msg))
    (cl:cons ':th (th msg))
    (cl:cons ':vx (vx msg))
    (cl:cons ':vy (vy msg))
    (cl:cons ':vth (vth msg))
))
