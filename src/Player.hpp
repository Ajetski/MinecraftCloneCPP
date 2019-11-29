class Player {
public:
	void setCamera() const;

	void setPos(float x, float y, float z);
	void setRot(float pitch, float yaw, float roll);

	const float& x() const;
	const float& y() const;
	const float& z() const;
	const float& pitch() const;
	const float& roll() const;
	const float& yaw() const;

private:
	float pos_x = 0, pos_y = 2, pos_z = 0;
	float rot_pitch = 0, rot_yaw = 0, rot_roll = 0;
};